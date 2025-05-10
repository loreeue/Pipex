/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:45:56 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/07 13:06:41 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_parse_commands(t_data *data, char **argv, int argc)
{
	int			i;
	t_parser	*node;
	char		**command;

	if (data->infile)
		i = 2;
	else
		i = 3;
	while (i < argc - 1)
	{
		command = ft_split(argv[i], ' ');
		if (!command)
			exit(EXIT_FAILURE);
		node = ft_new_node(command);
		if (!node)
		{
			ft_free_split(command);
			exit(EXIT_FAILURE);
		}
		ft_add_node(&data->commands, node);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		return (write(2, "Error: wrong number of arguments\n", 33), 1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		data.delim = argv[2];
		data.infile = NULL;
	}
	else
	{
		data.delim = NULL;
		data.infile = argv[1];
	}
	data.outfile = argv[argc - 1];
	data.commands = NULL;
	ft_parse_commands(&data, argv, argc);
	data.num_commands = ft_parserlen(data.commands);
	data.envp = envp;
	ft_exec_pipes(&data);
	ft_free_data(&data);
	return (0);
}
