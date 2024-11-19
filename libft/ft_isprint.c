/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:03:40 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:03:48 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint('9'));
	printf("%d\n", ft_isprint('+'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", isprint('\n'));
	printf("%d\n", isprint('A'));
	printf("%d\n", isprint('9'));
	printf("%d\n", isprint('+'));
}*/
