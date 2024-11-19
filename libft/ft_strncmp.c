/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:22:40 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/14 13:22:45 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n > i && (us1[i] != '\0' && us2[i] != '\0'))
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us1[i] == '\0' && us2[i] != '\0' && n > i)
		return (-1);
	else if (us1[i] != '\0' && us2[i] == '\0' && n > i)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_strncmp("hola", "hola", 3)); //0
	printf("%d\n", ft_strncmp("ahola", "chol", 3)); //-1
	printf("%d\n", ft_strncmp("chola", "ahola", 3)); //1
	printf("%d\n", ft_strncmp("", "a", 1));
	printf("%d\n", ft_strncmp("a", "", 1));
	printf("%d\n", ft_strncmp("hola", "adios", 3));
	printf("%d\n", ft_strncmp("", "", 3));
	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5)); ///falla en este

	printf("\n");

	printf("%d\n", strncmp("hola", "hola", 3));
	printf("%d\n", strncmp("ahola", "chol", 3));
	printf("%d\n", strncmp("chola", "ahola", 3));
	printf("%d\n", strncmp("", "a", 1));
	printf("%d\n", strncmp("a", "", 1));
	printf("%d\n", strncmp("hola", "adios", 3));
	printf("%d\n", strncmp("", "", 3));
	printf("%d\n", strncmp("abcdef", "abc\375xx", 5));
}*/
