/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:20:28 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/14 13:20:33 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	x;
	size_t	y;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	x = 0;
	y = dest_len;
	if (size == 0 || size <= y)
		return (src_len + size);
	while (src[x] != '\0' && x < size - y - 1)
	{
		dst[dest_len] = src[x];
		dest_len++;
		x++;
	}
	dst[dest_len] = '\0';
	return (y + src_len);
}

/*int	main(void)
{
	char	c[30] = "hola";
	printf("%zu\n", ft_strlcat(c, "loreto", 6));
}*/
