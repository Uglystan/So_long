/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:36:20 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 15:51:35 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_elem(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] != 'E' &&
			data->map[j][i] != 'P' && data->map[j][i] != 'C'
				&& data->map[j][i] != '1' && data->map[j][i] !=
				'0' && data->map[j][i] != '3')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_elem_nb(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == c)
				count ++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count != 1 && (c == 'P' || c == 'E'))
		return (0);
	if (count < 1 && c == 'C')
		return (0);
	return (1);
}

int	check_map_rectangle(t_data *data)
{
	data->ind.i = 0;
	data->ind.j = 0;
	while (data->map[0][data->ind.i] != '\0')
	{
		if (data->map[0][data->ind.i++] != '1')
			return (0);
	}
	while (data->map[data->ind.j] != NULL)
	{
		if (data->map[data->ind.j++][0] != '1')
			return (0);
	}
	while (data->ind.i > 0)
	{
		if (data->map[(data->height / 100) - 1][--data->ind.i] != '1')
			return (0);
	}
	while (data->ind.j > 0)
	{
		if (data->map[--data->ind.j][(data->weight / 100) - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_form_map(t_data *data)
{
	int	j;
	int	lenght;

	lenght = ft_strlenn(data->map[0]);
	j = 1;
	while (data->map[j] != NULL)
	{
		if ((int)ft_strlenn(data->map[j]) != lenght)
			return (0);
		j++;
	}
	return (1);
}

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e'
		|| argv[i - 3] != 'b' || argv[i - 4] != '.')
		return (0);
	if (i - 5 == -1)
		return (0);
	return (1);
}
