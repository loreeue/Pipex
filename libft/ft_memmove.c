/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:42 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 13:03:44 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

static void	copy_forward(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	copy_backward(char *dest, const char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (dest);
	if (dest < src)
		copy_forward((char *)dest, (const char *)src, n);
	else if (dest > src)
		copy_backward((char *)dest, (const char *)src, n);
	return (dest);
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	str1[] = "hola";
	unsigned char	str2[] = "loreto";
	int i;

	i = 0;
	ft_memmove(str1, str2, 3);
	printf("%s\n", str1);

	printf("\n");
    printf("Función de C:\n");
	unsigned char	str3[] = "hola";
	unsigned char	str4[] = "loreto";

	i = 0;
	memmove(str3, str4, 3);
	printf("%s\n", str3);
	return (0);
}*/
