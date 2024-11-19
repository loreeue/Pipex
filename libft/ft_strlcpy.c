/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:04:13 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 15:04:15 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*int	main(void)
{
	printf("Mi función:\n");
	char	dst[30] = "";

	printf("%zu\n", ft_strlcpy(dst, "aaa", 0));

	//NO FUNCIONA LA FUNCION DE C
	printf("\n");
	printf("Función de C:\n");
	char	dst2[30] = "";

	printf("%d\n", strlcpy(dst2, "holaaa", 4));
}*/
