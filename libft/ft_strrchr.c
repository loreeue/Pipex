/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:59:23 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/18 17:59:24 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*toreturn;
	char			*str;
	unsigned char	uc;

	i = 0;
	toreturn = 0;
	str = (char *)s;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			toreturn = (&str[i]);
		i++;
	}
	if (uc == '\0')
		return (&str[i]);
	return (toreturn);
}

/*int	main(void)
{
	int	c;

	c = 'o';
	printf("%s\n", ft_strrchr("holoa", c));
}*/
