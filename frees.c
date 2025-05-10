/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:01:30 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/07 19:06:47 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_parser(t_parser *parser)
{
	t_parser	*tmp;

	while (parser)
	{
		tmp = parser->next;
		if (parser->args)
			ft_free_split(parser->args);
		free(parser);
		parser = tmp;
	}
}

void	ft_free_data(t_data *data)
{
	ft_free_parser(data->commands);
}
