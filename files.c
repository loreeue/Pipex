/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:14 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/11 18:21:00 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_manage_infile(t_data *data)
{
	int	fd_in;

	fd_in = open(data->infile, O_RDONLY);
	if (fd_in < 0)
	{
		perror("Error opening file input");
		exit(EXIT_FAILURE);
	}
	else if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		close(fd_in);
		exit(EXIT_FAILURE);
	}
	close(fd_in);
}

void	ft_manage_outfile(t_data *data)
{
	int			fd_out;

	fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("Error opening file output");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		close(fd_out);
		exit(EXIT_FAILURE);
	}
	close(fd_out);
}
