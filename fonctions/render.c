/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:19:54 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 13:26:03 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	win_len(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y][x] != '\0')
		x++;
	while (data->map[y] != NULL)
		y++;
	data->weight = x * 100;
	data->height = (y * 100) + 60;
}

void	set_image_2(t_data *data, int *x, int *y)
{
	if (data->right_left == 2)
	{
		data->i.p = "./textures/caracter.xpm";
		data->i.img_p = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p, x, y);
		data->i.p2 = "./textures/saut2.xpm";
		data->i.i_p2 = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p2, x, y);
	}
	else if (data->right_left == 1)
	{
		data->i.p = "./textures/caracter_hori.xpm";
		data->i.img_p = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p, x, y);
		data->i.p2 = "./textures/Saut_hori.xpm";
		data->i.i_p2 = mlx_xpm_file_to_image(data->mlx_ptr, data->i.p2, x, y);
	}
}

void	set_image(t_data *data)
{
	int	x;
	int	y;

	x = data->weight;
	y = data->height;
	data->i.w = "./textures/Mur.xpm";
	data->i.im_w = mlx_xpm_file_to_image(data->mlx_ptr, data->i.w, &x, &y);
	data->i.f = "./textures/floor.xpm";
	data->i.im_f = mlx_xpm_file_to_image(data->mlx_ptr, data->i.f, &x, &y);
	data->i.c = "./textures/collect.xpm";
	data->i.im_c = mlx_xpm_file_to_image(data->mlx_ptr, data->i.c, &x, &y);
	data->i.e = "./textures/exit.xpm";
	data->i.im_e = mlx_xpm_file_to_image(data->mlx_ptr, data->i.e, &x, &y);
	set_image_2(data, &x, &y);
	data->i.en = "./textures/ennemi.xpm";
	data->i.i_en = mlx_xpm_file_to_image(data->mlx_ptr, data->i.en, &x, &y);
	data->i.bk = "./textures/background.xpm";
	data->i.i_bk = mlx_xpm_file_to_image(data->mlx_ptr, data->i.bk, &x, &y);
}

static void	choose_2(t_data *data)
{
	while (data->map[data->ind.j][data->ind.i] != '\0')
	{
		if (data->map[data->ind.j][data->ind.i] == '0' ||
		data->map[data->ind.j][data->ind.i] == '2')
			print_img(data, data->i.im_f, data->ind.x, data->ind.y);
		else if (data->map[data->ind.j][data->ind.i] == '1')
			print_img(data, data->i.im_w, data->ind.x, data->ind.y);
		else if (data->map[data->ind.j][data->ind.i] == 'C')
			print_img(data, data->i.im_c, data->ind.x, data->ind.y);
		else if (data->map[data->ind.j][data->ind.i] == '3')
			print_img(data, data->i.i_en, data->ind.x, data->ind.y);
		else if (data->map[data->ind.j][data->ind.i] == 'P')
			print_img(data, data->i.img_p, data->ind.x, data->ind.y);
		else if (data->map[data->ind.j][data->ind.i] == 'E')
			print_img(data, data->i.im_e, data->ind.x, data->ind.y);
		data->ind.x = data->ind.x + 100;
		data->ind.i++;
	}
}

void	choose_texture(t_data *data)
{
	data->ind.x = 0;
	data->ind.y = 0;
	data->ind.i = 0;
	data->ind.j = 0;
	while (data->map[data->ind.j] != NULL)
	{
		choose_2(data);
		data->ind.i = 0;
		data->ind.x = 0;
		data->ind.y = data->ind.y + 100;
		data->ind.j++;
	}
}
