/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:13 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 14:20:15 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlenn(const char *str);
char	*ft_itoa(int n);

#endif
