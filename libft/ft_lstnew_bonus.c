/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:25:49 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/26 12:41:25 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*toreturn;

	toreturn = malloc(sizeof(t_list));
	if (!toreturn)
		return (NULL);
	toreturn->content = content;
	toreturn->next = NULL;
	return (toreturn);
}
