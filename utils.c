/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:36:26 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/03 16:52:41 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parserlen(t_parser *parser)
{
	int	len;

	len = 0;
	while (parser)
	{
		len++;
		parser = parser->next;
	}
	return (len);
}

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

static void	ft_print_com(int i, t_parser *curr)
{
	int	j;

	printf("Command %d:\n", i);
	if (curr->args != NULL)
		printf("  args[0]: %s\n", curr->args[0]);
	j = 1;
	while (curr->args != NULL && curr->args[j])
	{
		printf("  args[%d]: %s\n", j, curr->args[j]);
		j++;
	}
}

void	ft_print_commands(t_parser *head)
{
	int			i;
	t_parser	*curr;

	i = 0;
	curr = head;
	while (curr)
	{
		ft_print_com(i, curr);
		curr = curr->next;
		i++;
	}
}
