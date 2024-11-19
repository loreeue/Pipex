/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:03:05 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:03:13 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_isascii('z'));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii('9'));
	printf("%d\n", ft_isascii('+'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", isascii('z'));
	printf("%d\n", isascii('A'));
	printf("%d\n", isascii('9'));
	printf("%d\n", isascii('+'));
}*/
