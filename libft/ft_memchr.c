/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:32:19 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/19 09:32:21 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	str = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n > i)
	{
		if (str[i] == uc)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	ptr[] = "holaloreto";
	char	*str;
	size_t i;

	i = 0;
	str = (char *)ft_memchr(ptr, 'l', 6);
	printf("%s\n", str);

	printf("\n");
	printf("Función de C:\n");
	unsigned char	ptr2[] = "holaloreto";
	char	*str2;

	i = 0;
	str2 = (char *)memchr(ptr2, 'l', 6);
	printf("%s\n", str2);

	return (0);
}*/
