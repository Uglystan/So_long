/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:57:40 by lgirault          #+#    #+#             */
/*   Updated: 2022/11/24 13:34:15 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		*len = *len + 6;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
}
