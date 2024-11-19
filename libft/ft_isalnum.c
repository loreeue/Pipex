/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:28 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:02:37 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_isalnum('z'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", ft_isalnum('+'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", isalnum('z'));
	printf("%d\n", isalnum('A'));
	printf("%d\n", isalnum('9'));
	printf("%d\n", isalnum('+'));
}*/
