/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:28 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:22:30 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_count_struct(char *str);
int		ft_printf(const char *str, ...);
char	*ft_strmalup(const char *str);
void	ft_putnbr(int n, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_unsi(unsigned int n, int *len);
void	ft_putnb_base(unsigned int n, char *base, int *len);
void	ft_putvoid(void *ptr, int *len);

#endif