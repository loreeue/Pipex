/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:03:56 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:04:05 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_strlen("Holaaaaaaa"));
	printf("%d\n", ft_strlen(""));
	printf("\n");
	printf("Función de C:\n");
	printf("%lu\n", strlen("Holaaaaaaa"));
	printf("%lu\n", strlen(""));
}*/
