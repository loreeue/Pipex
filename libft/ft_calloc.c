/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:33:58 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/22 12:34:00 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*toreturn;

	toreturn = malloc(nmemb * size);
	if (!toreturn)
		return (0);
	ft_bzero(toreturn, nmemb * size);
	return (toreturn);
}
