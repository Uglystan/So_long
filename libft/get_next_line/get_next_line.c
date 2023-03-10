/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:23:03 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 10:23:11 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*If 0, check if str[i] == c and return his index
If 1, check the number of '-1' in the string and return his index*/
int	check_cara(char *str, char c, int bool)
{
	int	i;

	i = 0;
	if (bool == 0)
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i] == c)
			return (i + 1);
		return (0);
	}
	else
	{
		while (str[i] == -1)
			i++;
		return (i);
	}
}

/*If 0, init the string with c.
If 1, init the string with '\0'*/
void	init_str(char *buff, char c, int bool)
{
	int	i;

	i = -1;
	if (bool == 0)
	{
		while (buff[++i] != '\n')
			buff[i] = c;
		buff[i] = c;
	}
	else
	{
		while (++i <= BUFFER_SIZE)
			buff[i] = c;
	}
}

/*create line with join. "clean" buff with '\0' for the 
next call and read again*/
int	no_new_line(char *buff, char **line, int fd, int *red)
{
	*line = join(*line, substr(buff, check_cara(buff, -1, 1),
				check_cara(buff, '\0', 0) - check_cara(buff, -1, 1)));
	init_str(buff, '\0', 1);
	*red = read(fd, buff, BUFFER_SIZE);
	if (*red < 0)
	{
		free (*line);
		return (0);
	}
	return (1);
}

/*Init red = 1. If -1 => read*/
int	init_read(char *buff, int *red, int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*line = ft_calloc(1, sizeof(char));
	if (!*line)
		return (0);
	*red = 1;
	if (buff[0] != -1)
	{
		*red = read(fd, buff, BUFFER_SIZE);
		if (*red < 0)
		{
			free (*line);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			red;

	buff[BUFFER_SIZE] = '\0';
	if (init_read(buff, &red, fd, &line) == 0)
		return (NULL);
	while (red != 0)
	{
		if (check_cara(buff, '\n', 0) != 0)
		{
			line = join(line, substr(buff, check_cara(buff, -1, 1),
						check_cara(buff, '\n', 0) - check_cara(buff, -1, 1)));
			init_str(buff, -1, 0);
			return (line);
		}
		if (no_new_line(buff, &line, fd, &red) == 0)
			return (NULL);
	}
	if (free_line(line) == 1)
		return (NULL);
	return (line);
}
