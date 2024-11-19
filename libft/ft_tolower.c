/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:04:11 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:04:20 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return (c);
	}
	return (c);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_tolower('c'));
	printf("%d\n", ft_tolower('A'));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", tolower('c'));
	printf("%d\n", tolower('A'));
}*/
