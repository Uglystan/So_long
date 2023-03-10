/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:20:45 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:20:47 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != c)
		{
			e++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (e);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static int	ft_split2(char **str, int size, int j)
{
	str[j] = malloc(sizeof(char) * (size + 1));
	if (!str[j])
	{
		ft_free(str, j);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		e;
	int		size;
	char	**str;

	i = 0;
	j = -1;
	str = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!str)
		return (NULL);
	while (++j < count_word(s, c))
	{
		while (s[i] == c)
			i++;
		size = size_word(s, c, i);
		if (ft_split2(str, size, j) == 0)
			return (NULL);
		e = 0;
		while (e < size)
			str[j][e++] = s[i++];
		str[j][e] = '\0';
	}
	str[j] = 0;
	return (str);
}
