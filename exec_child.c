/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:40:51 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/03 16:50:06 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close_unused_pipes(int num_commands, int i, int ***array_pipes)
{
	int	j;

	j = 0;
	while (j < num_commands - 1)
	{
		if (j != i && j != i - 1)
		{
			close((*array_pipes)[j][0]);
			close((*array_pipes)[j][1]);
		}
		j++;
	}
}

static void	ft_pipes_first_child(int i, int ***array_pipes, t_data *data)
{
	int	fd;

	if (data->infile)
		ft_manage_infile(data);
	else if (data->delim)
	{
		fd = ft_manage_heredoc(data);
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("dup2 heredoc");
			exit(1);
		}
		close(fd);
	}
	if (dup2((*array_pipes)[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 first child stdout");
		exit(1);
	}
	close((*array_pipes)[i][0]);
	close((*array_pipes)[i][1]);
}

static void	ft_pipes_middle_child(int i, int ***array_pipes)
{
	if (dup2((*array_pipes)[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 middle child stdin");
		exit(1);
	}
	if (dup2((*array_pipes)[i][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 middle child stdout");
		exit(1);
	}
	close((*array_pipes)[i][0]);
	close((*array_pipes)[i][1]);
	close((*array_pipes)[i - 1][0]);
	close((*array_pipes)[i - 1][1]);
}

static void	ft_pipes_last_child(int i, int ***array_pipes, t_data *data)
{
	if (dup2((*array_pipes)[i - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 last child stdin");
		exit(1);
	}
	ft_manage_outfile(data);
	close((*array_pipes)[i - 1][0]);
	close((*array_pipes)[i - 1][1]);
}

void	ft_exec_child(int i, int ***array_pipes, t_data *data)
{
	ft_close_unused_pipes(data->num_commands, i, array_pipes);
	if (i == 0)
		ft_pipes_first_child(i, array_pipes, data);
	else if (i == data->num_commands - 1)
		ft_pipes_last_child(i, array_pipes, data);
	else
		ft_pipes_middle_child(i, array_pipes);
	ft_find_path(data);
}
