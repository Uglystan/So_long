/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:40 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 13:29:11 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	del_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->i.im_w);
	mlx_destroy_image(data->mlx_ptr, data->i.im_f);
	mlx_destroy_image(data->mlx_ptr, data->i.im_c);
	mlx_destroy_image(data->mlx_ptr, data->i.img_p);
	mlx_destroy_image(data->mlx_ptr, data->i.im_e);
	mlx_destroy_image(data->mlx_ptr, data->i.i_p2);
	mlx_destroy_image(data->mlx_ptr, data->i.i_en);
	mlx_destroy_image(data->mlx_ptr, data->i.i_bk);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_map(t_data *data)
{
	free_map(data->map);
	free_map(data->map_backtrack);
	free_map(data->map_col);
	exit(EXIT_SUCCESS);
}

void	end(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	i;

	i = 0;
	del_img(data);
	mlx_destroy_window(mlx_ptr, win_ptr);
	free_map(data->map);
	free_map(data->map_backtrack);
	free_map(data->map_col);
	ft_lstclear(&data->ennemi);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
