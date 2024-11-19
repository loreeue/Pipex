/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:43:55 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 12:43:57 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	ptr[] = "hola loreto";
	int i;

	i = 0;
	ft_bzero(ptr, 4);
	while (i < 13)
	{
		printf("%c\n", ptr[i]);
		i++;
	}

	printf("\n");
	printf("Función de C:\n");
	unsigned char	ptr2[] = "hola loreto";

	i = 0;
	bzero(ptr2, 4);
	while (i < 13)
	{
		printf("%c\n", ptr2[i]);
		i++;
	}
	return (0);
}*/
