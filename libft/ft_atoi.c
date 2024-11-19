/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:02:08 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/10 20:02:18 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	ft_skip_whitespace(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
	{
		(*str)++;
	}
	return (**str);
}

static int	ft_get_sign(const char **str)
{
	int	signo;

	signo = 1;
	if (**str == '-')
	{
		signo = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (signo);
}

int	ft_atoi(const char *nptr)
{
	int			res;
	const char	*str;
	int			signo;

	res = 0;
	str = nptr;
	ft_skip_whitespace(&str);
	signo = ft_get_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (signo * res);
}

/*int main(void)
{
	printf("Mi función:\n");
	printf("%d\n", ft_atoi("-452"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("918"));
	printf("%d\n", ft_atoi("--918"));
	printf("%d\n", ft_atoi("8"));
	printf("%d\n", ft_atoi("-12"));
	printf("%d\n", ft_atoi("+124"));
	printf("\n");
	printf("Función de C:\n");
	printf("%d\n", atoi("-452"));
	printf("%d\n", atoi("0"));
	printf("%d\n", atoi("918"));
	printf("%d\n", atoi("--918"));
	printf("%d\n", atoi("8"));
	printf("%d\n", atoi("-12"));
	printf("%d\n", atoi("+124"));
}*/
