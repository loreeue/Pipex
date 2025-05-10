/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:44:12 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/07 19:17:02 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_path_from_env(char **envp)
{
	int		i;
	char	*path_env;

	i = 0;
	if (!envp[i])
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			return (path_env);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_find_executable(char *command, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*path;
	char	*temp;
	int		i;

	path_env = ft_get_path_from_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (ft_free_split(paths), NULL);
		path = ft_strjoin(temp, command);
		free(temp);
		if (!path)
			return (ft_free_split(paths), NULL);
		if (access(path, X_OK) == 0)
			return (ft_free_split(paths), path);
		free(path);
	}
	return (ft_free_split(paths), NULL);
}

void	ft_find_path(t_data *data)
{
	char	*path;

	if (!data->commands->args)
		return ;
	if (ft_strchr(data->commands->args[0], '/'))
	{
		if (access(data->commands->args[0], X_OK) == 0)
			execve(data->commands->args[0], data->commands->args, data->envp);
		else
		{
			perror("command not found");
			ft_free_data(data);
			exit(EXIT_FAILURE);
		}
	}
	path = ft_find_executable(data->commands->args[0], data->envp);
	if (!path || execve(path, data->commands->args, data->envp) == -1)
	{
		perror("command not found");
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}
