/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemi_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:06:10 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 14:38:17 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	move(t_data *data, int y, int x, char *str)
{
	if (data->map[data->j_ply + y][data->i_ply + x] != '1')
	{
		if (data->map[data->j_ply + y][data->i_ply + x] ==
			'E' && data->c == data->nb_c)
		{
			ft_printf(str, ++data->nb_move, data->c);
			end(data->mlx_ptr, data->win_ptr, data);
		}
		if (data->map[data->j_ply + y][data->i_ply + x] == '3')
			data->map[data->j_ply + y][data->i_ply + x] = '0';
		if (data->map[data->j_ply + y][data->i_ply + x] == 'C')
			collect_move(data);
		else
			data->boolean = 0;
		if (data->map[data->j_ply + y][data->i_ply + x] != 'E')
		{
			data->map[data->j_ply][data->i_ply] = '0';
			data->map[data->j_ply + y][data->i_ply + x] = 'P';
			data->nb_move++;
		}
	}
	return (1);
}

int	move_player(t_data *data, int keysym, char *str)
{	
	find_letter(data, 'P', &data->i_ply, &data->j_ply);
	if (keysym == XK_s || keysym == XK_Down)
		move(data, 1, 0, str);
	else if (keysym == XK_w || keysym == XK_Up)
		move(data, -1, 0, str);
	else if (keysym == XK_a || keysym == XK_Left)
	{
		data->right_left = 1;
		move(data, 0, -1, str);
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		data->right_left = 2;
		move(data, 0, 1, str);
	}
	return (1);
}

int	move_ennemie(t_data *data, int x, t_enn **ennemi)
{
	t_enn	*ptr;

	ptr = *ennemi;
	if (data->map[ptr->j_ennemi][ptr->i_ennemi + x] == '0' ||
		data->map[ptr->j_ennemi][ptr->i_ennemi + x] == 'P')
	{
		if (data->map[ptr->j_ennemi][ptr->i_ennemi + x] == 'P')
		{
			ft_printf("Perdu touche par un ennemie");
			end(data->mlx_ptr, data->win_ptr, data);
		}
		data->map[ptr->j_ennemi][ptr->i_ennemi] = '0';
		data->map[ptr->j_ennemi][ptr->i_ennemi + x] = '3';
		ptr->i_ennemi = ptr->i_ennemi + x;
	}
	else
		ptr->choix_ennemi = x;
	return (1);
}

int	choix_ennemie(t_data *data, t_enn **ennemi)
{
	t_enn	*ptr;
	int		i;
	int		j;

	ptr = *ennemi;
	find_letter(data, 'P', &i, &j);
	while (ptr != NULL)
	{
		if (ptr->j_ennemi == j && ptr->i_ennemi == i)
			ptr->vie = 0;
		if (ptr->vie == 1)
		{
			if (ptr->choix_ennemi == -1)
				move_ennemie(data, 1, &ptr);
			if (ptr->choix_ennemi == 1)
				move_ennemie(data, -1, &ptr);
		}
		ptr = ptr->next;
	}
	return (1);
}
