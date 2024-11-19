/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:18:37 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/26 12:40:13 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	head = *lst;
	while (head)
	{
		temp = head->next;
		(*del)(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
}
