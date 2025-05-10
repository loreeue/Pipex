/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:03:32 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/07 19:30:14 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_init_pipes(int num_commands, int ***array_pipes,
	pid_t **array_pids)
{
	int	i;

	*array_pipes = (int **) malloc((num_commands - 1) * sizeof(int *));
	*array_pids = (pid_t *) malloc(num_commands * sizeof(pid_t));
	if (!*array_pipes || !*array_pids)
		return ;
	i = 0;
	while (i < num_commands - 1)
	{
		(*array_pipes)[i] = (int *) malloc(2 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < num_commands - 1)
	{
		if (pipe((*array_pipes)[i]) == -1)
		{
			perror("Error init pipes");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	ft_manage_commands(t_data *data, int **array_pipes,
	pid_t *array_pids)
{
	int			i;
	pid_t		pid;
	t_parser	*com;

	i = 0;
	com = data->commands;
	while (i < data->num_commands)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_free_data(data);
			perror("Error fork pipes");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			data->commands = com;
			ft_exec_child(i, &array_pipes, data);
		}
		else
			array_pids[i] = pid;
		com = com->next;
		i++;
	}
}

static void	ft_close_all_pipes(t_data *data, int **array_pipes)
{
	int	i;

	i = 0;
	while (i < data->num_commands - 1)
	{
		close(array_pipes[i][0]);
		close(array_pipes[i][1]);
		i++;
	}
}

static void	ft_finish_exec(int num_commands, int ***array_pipes,
	pid_t **array_pids)
{
	int	i;
	int	status;

	i = 0;
	while (i < num_commands - 1)
	{
		close((*array_pipes)[i][0]);
		close((*array_pipes)[i][1]);
		i++;
	}
	i = 0;
	while (i < num_commands)
	{
		waitpid((*array_pids)[i], &status, 0);
		i++;
	}
	i = 0;
	while (i < num_commands - 1)
	{
		free((*array_pipes)[i]);
		i++;
	}
	free(*array_pipes);
	free(*array_pids);
}

void	ft_exec_pipes(t_data *data)
{
	int			**array_pipes;
	pid_t		*array_pids;

	data->commands = data->commands;
	ft_init_pipes(data->num_commands, &array_pipes, &array_pids);
	ft_manage_commands(data, array_pipes, array_pids);
	ft_close_all_pipes(data, array_pipes);
	ft_finish_exec(data->num_commands, &array_pipes, &array_pids);
}
