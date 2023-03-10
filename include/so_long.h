/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:20:10 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/20 12:35:22 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_img
{
	void	*im_w;
	void	*im_f;
	void	*im_c;
	void	*img_p;
	void	*im_e;
	void	*i_p2;
	void	*i_en;
	void	*i_bk;
	char	*e;
	char	*w;
	char	*f;
	char	*c;
	char	*p;
	char	*p2;
	char	*en;
	char	*bk;
}t_img;

typedef struct s_enn
{
	int				j_ennemi;
	int				i_ennemi;
	int				choix_ennemi;
	int				vie;
	struct s_enn	*next;
}t_enn;

typedef struct s_ind
{
	int	x;
	int	y;
	int	i;
	int	j;
}t_ind;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_path;
	char	**map;
	char	**map_backtrack;
	char	**map_col;
	int		j_ply;
	int		i_ply;
	int		right_left;
	int		boucle_move_ennemi;
	int		boucle_animation;
	int		weight;
	int		height;
	int		nb_move;
	int		c;
	int		nb_c;
	int		boolean;
	t_enn	*ennemi;
	t_img	i;
	t_ind	ind;
}t_data;

int		set_map(t_data *data);
int		move_player(t_data *data, int keysym, char *str);
int		global_check(t_data *data);
int		global_check2(t_data *data);
int		check_valid_elem(t_data *data);
int		check_elem_nb(t_data *data, char c);
int		check_map_rectangle(t_data *data);
int		check_form_map(t_data *data);
int		handle_input(int keysym, t_data *data);
int		close_window(t_data *data);
int		handle_no_event(t_data *data);
int		launch_game(t_data *data);
int		backtrack(char **map_backtrack, int j, int i, int dep);
int		check_argv(char *argv);
int		find_letter(t_data *data, char c, int *i, int *j);
int		count_collect(char **map, int *nbcollect);
int		backtrack_col(char **map_backtrack_col, int j, int i, int dep);
int		backtrack_move(char **map_backtrack, int j, int i);
int		choix_ennemie(t_data *data, t_enn **ennemi);
void	win_len(t_data *data);
void	choose_texture(t_data *data);
void	set_image(t_data *data);
void	header(t_data *data);
void	collect_move(t_data *data);
void	ft_lstadd_back(t_enn **lst, t_enn *new);
void	ft_lstclear(t_enn **lst);
void	free_all_map(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
void	end(void *mlx_ptr, void *win_ptr, t_data *data);
void	free_map(char **map);
void	del_img(t_data *data);
t_enn	*lst_collect(t_data *data);
t_enn	*ft_lstnew(int choix_ennemi, int j_ennemi, int i_ennemi);

#endif