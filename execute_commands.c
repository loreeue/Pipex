/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:03:32 by loruzqui          #+#    #+#             */
/*   Updated: 2024/11/09 16:03:34 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path_from_env(char **envp)
{
	int		i;
	char	*path_env;

	i = 0;
	if (!envp[i])
		return (NULL);
	while (i <= *envp[i])
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

char	*ft_find_executable(char *command, char **envp)
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
	while (paths[i++])
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

void	ft_execute_with_path(char **command, char **envp)
{
	char	*path;

	path = ft_find_executable(command[0], envp);
	if (path && execve(path, command, envp) == -1)
	{
		perror("Error execve");
		free(path);
		ft_free_split(command);
		exit(EXIT_FAILURE);
	}
	else if (!path)
	{
		write(2, "Command not found\n", 18);
		ft_free_split(command);
		exit(EXIT_FAILURE);
	}
	ft_free_split(command);
	free(path);
}
