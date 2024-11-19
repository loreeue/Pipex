/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:03:25 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:03:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_isdigit('z'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('+'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", isdigit('z'));
	printf("%d\n", isdigit('A'));
	printf("%d\n", isdigit('9'));
	printf("%d\n", isdigit('+'));
}*/
