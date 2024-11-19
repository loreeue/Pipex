/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:07:55 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/19 10:07:57 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	int		i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	n = ft_strlen(little);
	while (big[i] != '\0' && i + n <= len)
	{
		j = 0;
		while (j < n && big[i + j] == little[j])
		{
			j++;
		}
		if (j == n)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("Mi función:\n");
	printf("%s\n", ft_strnstr("hola loreto que tal", "lo", 4));
	printf("%s\n", ft_strnstr("hola loreto que tal", "lo", 15));
	printf("%s\n", ft_strnstr("hola loreto que tal", "", 17));
	printf("%s\n", ft_strnstr("", "hol", 3));
	printf("%s\n", ft_strnstr("hola loreto que tal", "lolo", 10));

	//NO FUNCIONA LA FUNCIÓN DE C
	printf("\n");
	printf("Función de C:\n");
	printf("%s\n", strnstr("hola loreto que tal", "lo", 4));
	printf("%s\n", strnstr("hola loreto que tal", "lo", 15));
	printf("%s\n", strnstr("hola loreto que tal", "", 17));
	printf("%s\n", strnstr("", "hol", 3));
	printf("%s\n", strnstr("hola loreto que tal", "lolo", 10));

	return (0);
}*/
