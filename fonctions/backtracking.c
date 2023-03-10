/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:23:43 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:00 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_win(char pos, char lettre)
{
	if (pos == lettre)
		return (1);
	return (0);
}

int	backtrack_move(char **map_backtrack, int j, int i)
{
	if (map_backtrack[j][i + 1] != '1' && map_backtrack[j][i + 1] != '2')
	{
		map_backtrack[j][i] = '2';
		return (1);
	}
	else if (map_backtrack[j + 1][i] != '1' && map_backtrack[j + 1][i] != '2')
	{
		map_backtrack[j][i] = '2';
		return (2);
	}
	else if (map_backtrack[j][i - 1] != '1' && map_backtrack[j][i - 1] != '2')
	{
		map_backtrack[j][i] = '2';
		return (3);
	}
	else if (map_backtrack[j - 1][i] != '1' && map_backtrack[j - 1][i] != '2')
	{
		map_backtrack[j][i] = '2';
		return (4);
	}
	else
	{
		map_backtrack[j][i] = '2';
		return (0);
	}
}

int	backtrack_condition(char **map_backtrack, int j, int i, int dep)
{
	if (dep == 1)
	{	
		if (backtrack(map_backtrack, j, i + 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move(map_backtrack, j, i);
	if (dep == 2)
	{
		if (backtrack(map_backtrack, j + 1, i, dep) == 1)
			return (1);
	}
	dep = backtrack_move(map_backtrack, j, i);
	if (dep == 3)
	{
		if (backtrack(map_backtrack, j, i - 1, dep) == 1)
			return (1);
	}
	dep = backtrack_move(map_backtrack, j, i);
	if (dep == 4)
	{
		if (backtrack(map_backtrack, j - 1, i, dep) == 1)
			return (1);
	}
	return (0);
}

int	backtrack(char **map_backtrack, int j, int i, int dep)
{
	if (is_win(map_backtrack[j][i], 'E') == 1)
		return (1);
	dep = backtrack_move(map_backtrack, j, i);
	if (backtrack_condition(map_backtrack, j, i, dep) == 1)
		return (1);
	return (0);
}
