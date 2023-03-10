/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:20:36 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:20:38 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nb;

	i = ft_count(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	nb = n;
	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}
