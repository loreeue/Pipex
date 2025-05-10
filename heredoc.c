/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:10:55 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/03 16:51:55 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_print_prompt(void)
{
	write(STDOUT_FILENO, COLOR_USERS, ft_strlen(COLOR_USERS));
	write(STDOUT_FILENO, "heredoc> ", ft_strlen("heredoc> "));
	write(STDOUT_FILENO, COLOR_RESET, ft_strlen(COLOR_RESET));
}

static void	ft_read_heredoc(int fd, char *delim)
{
	char	*line;

	while (1)
	{
		ft_print_prompt();
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, delim, ft_strlen(delim) + 1) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

int	ft_manage_heredoc(t_data *data)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe:");
		exit(EXIT_FAILURE);
	}
	ft_read_heredoc(pipefd[1], data->delim);
	close(pipefd[1]);
	return (pipefd[0]);
}
