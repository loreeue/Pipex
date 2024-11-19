/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:05:54 by loruzqui          #+#    #+#             */
/*   Updated: 2024/10/25 17:05:56 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_files
{
	char	*input_file;
	char	*output_file;
}	t_files;

//FUNCIONES LIBRERÍA
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//FUNCIONES HANDLE_ERRORS
void	ft_handle_pipe_error(int pipe_result);
void	ft_handle_fork_error(pid_t fork_result);
int		ft_handle_open_error(const char *file, int flags, mode_t mode);
//FUNCIONES EXECUTE_COMMANDS
char	*ft_get_path_from_env(char **envp);
char	*ft_find_executable(char *command, char **envp);
void	ft_execute_with_path(char **command, char **envp);
//FUNCIONES PIPEX
void	ft_free_split(char **split);
void	ft_child_process(int *fd, char *input, char **c1, char **envp);
void	ft_parent_process(int *fd, char *output, char **c2, char **envp);
void	ft_execute_command(char **c1, char **c2, t_files files, char **envp);
int		main(int argc, char **argv, char **envp);

#endif
