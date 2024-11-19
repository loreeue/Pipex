/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:16:51 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 12:16:54 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n > i)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	printf("Mi función:\n");
	unsigned char	ptr[] = "hola loreto";
	size_t i;

	i = 0;
	ft_memset(ptr, 'x', 4);
	printf("%s\n", ptr);

	printf("\n");
	printf("Función de C:\n");
	unsigned char	ptr2[] = "hola loreto";

	i = 0;
	memset(ptr2, 'x', 4);
	printf("%s\n", ptr2);

	return (0);
}*/
