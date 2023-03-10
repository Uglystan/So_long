/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:19:16 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 15:40:09 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_no_event(t_data *data)
{
	if (data->boucle_move_ennemi % 10000 == 1)
	{
		choix_ennemie(data, &data->ennemi);
		choose_texture(data);
	}
	find_letter(data, 'P', &data->ind.x, &data->ind.y);
	data->ind.x = data->ind.x * 100;
	data->ind.y = data->ind.y * 100;
	if (data->boucle_animation % 10000 == 0)
		print_img(data, data->i.i_p2, data->ind.x, data->ind.y);
	if (data->boucle_animation % 20000 == 0)
		print_img(data, data->i.img_p, data->ind.x, data->ind.y);
	data->boucle_move_ennemi++;
	data->boucle_animation++;
	if (data->boucle_move_ennemi == 10001)
		data->boucle_move_ennemi = 0;
	if (data->boucle_animation == 20005)
		data->boucle_animation = 0;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	char	*str;

	str = "Gagne en %d coups avec %d collectable";
	if (keysym == XK_Escape)
		end(data->mlx_ptr, data->win_ptr, data);
	if (keysym == XK_s || keysym == XK_a || keysym == XK_w || keysym == XK_d
		||keysym == XK_Up || keysym == XK_Down
		|| keysym == XK_Right || keysym == XK_Left)
	{
		move_player(data, keysym, str);
		if (data->boolean != 1)
		{
			del_img(data);
			set_image(data);
		}
		header(data);
		choose_texture(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	end(data->mlx_ptr, data->win_ptr, data);
	return (0);
}
