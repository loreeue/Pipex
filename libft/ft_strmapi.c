/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:17:50 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/24 12:17:52 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*toreturn;
	int		i;

	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	toreturn = malloc((len + 1) * sizeof(char));
	if (!toreturn)
		return (NULL);
	i = 0;
	while (len > i)
	{
		toreturn[i] = (*f)(i, s[i]);
		i++;
	}
	toreturn[i] = '\0';
	return (toreturn);
}

/*char	ft_test(unsigned int i, char s)
{
	s += i;
	return (s);
}

int	main()
{
	char	str[] = "hola";

	printf("%s\n", ft_strmapi(str, ft_test));
}*/
