/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:28 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:04:36 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
		return (c);
	}
	return (c);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_toupper('c'));
	printf("%d\n", ft_toupper('A'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", toupper('c'));
	printf("%d\n", toupper('A'));
}*/
