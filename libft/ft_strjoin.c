/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:20:53 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:20:55 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
