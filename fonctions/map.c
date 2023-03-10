/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:19:41 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/20 12:45:16 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_map_3(t_data *data, char *str)
{
	data->map = ft_split(str, '\n');
	if (data->map == NULL)
	{
		free(str);
		ft_printf("Error\nSplit tableau");
		exit(EXIT_SUCCESS);
	}
	data->map_backtrack = ft_split(str, '\n');
	if (data->map_backtrack == NULL)
	{
		free(str);
		free_map(data->map);
		ft_printf("Error\nSplit tableau");
		exit(EXIT_SUCCESS);
	}
	data->map_col = ft_split(str, '\n');
	if (data->map_backtrack == NULL)
	{
		free(str);
		free_map(data->map);
		free_map(data->map_backtrack);
		ft_printf("Error\nSplit tableau");
		exit(EXIT_SUCCESS);
	}
}

void	set_map_2(t_data *data, char *str, int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	if (temp == NULL)
	{
		free(str);
		ft_printf("Error\nFichier map vide");
		exit(EXIT_SUCCESS);
	}
	while (temp != NULL)
	{
		if (ft_strlenn(temp) < 2 || str == NULL)
		{
			free(str);
			free(temp);
			ft_printf("Error\nMap avec saut a la ligne");
			exit(EXIT_SUCCESS);
		}
		str = join(str, temp);
		temp = get_next_line(fd);
	}
	set_map_3(data, str);
	free(str);
}

int	set_map(t_data *data)
{
	char	*str;
	int		fd;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (0);
	str[0] = '\0';
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s", "Error\nLe path n'est pas valide");
		free(str);
		return (0);
	}
	set_map_2(data, str, fd);
	return (1);
}

int	global_check(t_data *data)
{
	if (check_valid_elem(data) == 0)
	{
		ft_printf("Error\nLes elements de la carte ne sont pas valides");
		return (0);
	}
	if (check_elem_nb(data, 'P') == 0)
	{
		ft_printf("Error\nNombre de personnage non valide");
		return (0);
	}
	if (check_elem_nb(data, 'E') == 0)
	{
		ft_printf("Error\nNombre de sortie non valide");
		return (0);
	}
	if (check_elem_nb(data, 'C') == 0)
	{
		ft_printf("Error\nNombre de collectable non valide");
		return (0);
	}
	return (1);
}

int	global_check2(t_data *data)
{
	int	dep;

	dep = -1;
	find_letter(data, 'P', &data->i_ply, &data->j_ply);
	if (check_form_map(data) == 0)
	{
		ft_printf("Error\nLa carte n'est pas rectangle");
		return (0);
	}
	if (check_map_rectangle(data) == 0)
	{
		ft_printf("Error\nLa carte n'est pas entoure de 1");
		return (0);
	}
	if (backtrack(data->map_backtrack, data->j_ply, data->i_ply, dep) == 0)
	{
		ft_printf("Error\nLa sortie n'est pas accessible");
		return (0);
	}
	if (backtrack_col(data->map_col, data->j_ply, data->i_ply, dep) == 0)
	{
		ft_printf("Error\nLes collectibles ne sont pas accessible");
		return (0);
	}
	return (1);
}
