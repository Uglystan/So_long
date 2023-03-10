/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:52 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:22:54 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		free_line(char *line);
char	*get_next_line(int fd);
char	*join(char *s1, char *s2);
char	*substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t elemCount, size_t elementSize);

#endif