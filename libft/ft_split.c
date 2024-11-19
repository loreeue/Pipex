/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:42:02 by loruzqui          #+#    #+#             */
/*   Updated: 2024/09/22 16:42:04 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i--]);
	}
	free(str);
	return (NULL);
}

static int	ft_aux(char const *s, char c, int *start, int i)
{
	while (s[i] == c)
		i++;
	*start = i;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	matrix = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		i = ft_aux(s, c, &start, i);
		if (i > start)
		{
			matrix[j] = ft_substr(s, start, i - start);
			if (matrix[j] == NULL)
				return (ft_free(matrix, j));
			j++;
		}
	}
	matrix[j] = NULL;
	return (matrix);
}

/*int	main(void)
{
	char	**res = ft_split("hola+que+tal+estas", '+');
	int		i;

	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}*/
