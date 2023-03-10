/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:45:36 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/20 12:50:27 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	put_backgr(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->height - 60;
	while (x <= data->weight)
	{
		print_img(data, data->i.i_bk, x, y);
		x = x + 100;
	}
}

void	header(t_data *data)
{
	char	*str;
	char	*count;
	char	*print;

	str = "Nombre de deplacement: ";
	count = ft_itoa(data->nb_move);
	print = ft_strjoin(str, count);
	if (print == NULL)
	{
		end(data->mlx_ptr, data->win_ptr, data);
		exit(EXIT_FAILURE);
	}
	put_backgr(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->weight
		- (data->weight * 66 / 100), data->height - 25, 0xFFFFFF, print);
	free(print);
	free(count);
	str = "Nombre d'item: ";
}

int	launch_game(t_data *data)
{
	if (set_map(data) == 0)
		return (0);
	win_len(data);
	if (global_check(data) == 0 || global_check2(data) == 0)
		free_all_map(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr
		= mlx_new_window(data->mlx_ptr, data->weight, data->height, "So_Long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	data->ennemi = lst_collect(data);
	set_image(data);
	header(data);
	choose_texture(data);
	count_collect(data->map, &data->nb_c);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, &close_window, data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.nb_move = 0;
	data.c = 0;
	data.boolean = 0;
	data.boucle_move_ennemi = 0;
	data.boucle_animation = 0;
	data.right_left = 1;
	data.map_path = argv[1];
	if (argc == 2)
	{
		if (check_argv(data.map_path) == 0)
		{
			ft_printf("Error\nFichier map ne se termine pas par .ber");
			return (0);
		}
		if (launch_game(&data) == 0)
			return (0);
	}
	else
		ft_printf("Error\nSaisissez 2 arguments");
}
