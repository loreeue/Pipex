/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:45:56 by loruzqui          #+#    #+#             */
/*   Updated: 2024/10/25 16:45:58 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_child_process(int *fd, char *input, char **c1, char **envp)
{
	int	in_fd;

	in_fd = ft_handle_open_error(input, O_RDONLY, 0);
	if (in_fd < 0)
	{
		close(fd[0]);
		close(fd[1]);
		ft_free_split(c1);
		exit(EXIT_FAILURE);
	}
	dup2(in_fd, 0);
	close(in_fd);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	ft_execute_with_path(c1, envp);
}

void	ft_parent_process(int *fd, char *output, char **c2, char **envp)
{
	int	out_fd;

	waitpid(-1, NULL, 0);
	out_fd = ft_handle_open_error(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
	{
		close(fd[0]);
		close(fd[1]);
		ft_free_split(c2);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], 0);
	dup2(out_fd, 1);
	close(fd[0]);
	close(fd[1]);
	close(out_fd);
	ft_execute_with_path(c2, envp);
}

void	ft_execute_command(char **c1, char **c2, t_files files, char **envp)
{
	int		fd[2];
	pid_t	pid;

	ft_handle_pipe_error(pipe(fd));
	pid = fork();
	if (pid < 0)
	{
		ft_free_split(c1);
		ft_free_split(c2);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	ft_handle_fork_error(pid);
	if (pid == 0)
	{
		ft_free_split(c2);
		ft_child_process(fd, files.input_file, c1, envp);
	}
	else
	{
		ft_free_split(c1);
		ft_parent_process(fd, files.output_file, c2, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_files	files;
	char	**input_divided1;
	char	**input_divided2;

	if (argc != 5)
		return (write(2, "Error: wrong number of arguments\n", 33), 1);
	files.input_file = argv[1];
	files.output_file = argv[4];
	input_divided1 = ft_split(argv[2], ' ');
	if (!input_divided1)
		return (1);
	input_divided2 = ft_split(argv[3], ' ');
	if (!input_divided2)
		return (ft_free_split(input_divided1), 1);
	ft_execute_command(input_divided1, input_divided2, files, envp);
	ft_free_split(input_divided1);
	ft_free_split(input_divided2);
	return (0);
}
