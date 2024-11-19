/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:39:42 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/19 09:39:44 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n > i)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	ptr1[] = "hola";
	unsigned char	ptr2[] = "hola";

	unsigned char	ptr3[] = "ahola";
	unsigned char	ptr4[] = "hola";

	unsigned char	ptr5[] = "hola";
	unsigned char	ptr6[] = "ahola";

	printf("%d\n", ft_memcmp(ptr1, ptr2, 4));
	printf("%d\n", ft_memcmp(ptr1, ptr2, 6));
	printf("%d\n", ft_memcmp(ptr3, ptr4, 6));
	printf("%d\n", ft_memcmp(ptr5, ptr6, 6));

	printf("\n");
	printf("Función de C:\n");

	printf("%d\n", memcmp(ptr1, ptr2, 4));
	printf("%d\n", memcmp(ptr1, ptr2, 6));
	printf("%d\n", memcmp(ptr3, ptr4, 6));
	printf("%d\n", memcmp(ptr5, ptr6, 6));

	return (0);
}*/
