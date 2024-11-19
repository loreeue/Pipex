/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:12:47 by loruzqui          #+#    #+#             */
/*   Updated: 2024/10/25 19:12:50 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_handle_pipe_error(int pipe_result)
{
	if (pipe_result == -1)
	{
		perror("Error pipe");
		exit(EXIT_FAILURE);
	}
}

void	ft_handle_fork_error(pid_t fork_result)
{
	if (fork_result == -1)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
}

int	ft_handle_open_error(const char *file, int flags, mode_t mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd == -1)
	{
		perror("Error open file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
