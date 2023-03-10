/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:49:27 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 14:25:03 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_move(t_data *data)
{
	int	x;
	int	y;

	x = data->weight;
	y = data->height;
	mlx_destroy_image(data->mlx_ptr, data->i.img_p);
	mlx_destroy_image(data->mlx_ptr, data->i.i_p2);
	data->i.p = "./textures/caracter3.xpm";
	data->i.img_p = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p, &x, &y);
	data->i.p2 = "./textures/caracter3.xpm";
	data->i.i_p2 = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p2, &x, &y);
	data->c++;
	data->boolean = 1;
}

int	find_letter(t_data *data, char c, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (data->map[*j] != NULL)
	{
		while (data->map[*j][*i] != c && data->map[*j][*i] != '\0')
			*i = *i + 1;
		if (data->map[*j][*i] == c)
		{
			return (1);
		}
		*i = 0;
		*j = *j + 1;
	}
	return (0);
}

int	count_collect(char **map, int *nbcollect)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*nbcollect = 0;
	while (map[j] != NULL)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				*nbcollect = *nbcollect + 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (*nbcollect);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
}
