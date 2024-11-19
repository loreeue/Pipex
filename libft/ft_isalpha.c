/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:46 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:02:56 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_isalpha('z'));
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('9'));
	printf("%d\n", ft_isalpha('+'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", isalpha('z'));
	printf("%d\n", isalpha('A'));
	printf("%d\n", isalpha('9'));
	printf("%d\n", isalpha('+'));
}*/
