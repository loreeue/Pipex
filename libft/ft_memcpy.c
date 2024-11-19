/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:49:09 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 12:49:12 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	str1[] = "hola";
	unsigned char	str2[] = "loreto";
	int i;

	i = 0;
	ft_memcpy(str1, str2, 3);
	while (i < 13)
	{
		printf("%c\n", str1[i]);
		i++;
	}

	printf("\n");
    printf("Función de C:\n");
	unsigned char	str3[] = "hola";
	unsigned char	str4[] = "loreto";

	i = 0;
	memcpy(str3, str4, 3);
	while (i < 13)
	{
		printf("%c\n", str3[i]);
		i++;
	}

	return (0);
}*/
