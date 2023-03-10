/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:28:53 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/20 13:01:55 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	backtrack_move_col(char **ma, int j, int i)
{
	if (ma[j][i + 1] != '1' && ma[j][i + 1] != '2' && ma[j][i + 1] != 'E')
	{
		ma[j][i] = '2';
		return (1);
	}
	else if (ma[j + 1][i] != '1' && ma[j + 1][i] != '2' && ma[j + 1][i] != 'E')
	{
		ma[j][i] = '2';
		return (2);
	}
	else if (ma[j][i - 1] != '1' && ma[j][i - 1] != '2' && ma[j][i - 1] != 'E')
	{
		ma[j][i] = '2';
		return (3);
	}
	else if (ma[j - 1][i] != '1' && ma[j - 1][i] != '2' && ma[j - 1][i] != 'E')
	{
		ma[j][i] = '2';
		return (4);
	}
	else
	{
		ma[j][i] = '2';
		return (0);
	}
}

int	backtrack_collect_condition(char **map_backtrack_col, int j, int i, int dep)
{
	if (dep == 1)
	{	
		if (backtrack_col(map_backtrack_col, j, i + 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_backtrack_col, j, i);
	if (dep == 2)
	{
		if (backtrack_col(map_backtrack_col, j + 1, i, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_backtrack_col, j, i);
	if (dep == 3)
	{
		if (backtrack_col(map_backtrack_col, j, i - 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move_col(map_backtrack_col, j, i);
	if (dep == 4)
	{
		if (backtrack_col(map_backtrack_col, j - 1, i, dep) == 1)
			return (1);
	}
	return (0);
}

int	backtrack_col(char **map_backtrack_col, int j, int i, int dep)
{
	int	c;

	c = 0;
	dep = backtrack_move_col(map_backtrack_col, j, i);
	backtrack_collect_condition(map_backtrack_col, j, i, dep);
	if (count_collect(map_backtrack_col, &c) == 0)
		return (1);
	return (0);
}
