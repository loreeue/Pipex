/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:45:07 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 17:45:09 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	uc;

	i = 0;
	str = (char *)s;
	uc = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == uc)
			return (&str[i]);
		i++;
	}
	if (uc == '\0')
		return (&str[i]);
	return (0);
}

/*int	main(void)
{
	int	c;

	c = 'o';
	printf("%s\n", ft_strchr("hola", c));
}*/
