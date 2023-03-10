/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:12 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:22:14 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb_base(unsigned int n, char *base, int *len)
{
	if (n > 15)
	{
		ft_putnb_base(n / 16, base, len);
	}
	ft_putchar(base[n % 16], len);
}
