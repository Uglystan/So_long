/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_collect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:35:30 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/18 14:38:04 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_lstclear(t_enn **lst)
{
	t_enn	*save;

	if (lst != NULL)
	{
		while ((*lst) != NULL)
		{
			save = (*lst)->next;
			free((*lst));
			(*lst) = save;
		}
	}
}

t_enn	*ft_lstnew(int choix_ennemi, int j_ennemi, int i_ennemi)
{
	t_enn	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
		return (NULL);
	a->vie = 1;
	a->choix_ennemi = choix_ennemi;
	a->j_ennemi = j_ennemi;
	a->i_ennemi = i_ennemi;
	a->next = NULL;
	return (a);
}

void	ft_lstadd_back(t_enn **lst, t_enn *new)
{
	t_enn	*ptr;

	ptr = *lst;
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

t_enn	*lst_collect(t_data *data)
{
	t_enn	*ennemi;
	t_enn	*temp;
	int		i;
	int		j;

	if (find_letter(data, '3', &i, &j) == 0)
		return (NULL);
	ennemi = ft_lstnew(1, j, i);
	while (data->map[j] != NULL)
	{
		while (data->map[j][i] != '\0')
		{
			i++;
			if (data->map[j][i] == '3')
			{
				temp = ft_lstnew(1, j, i);
				if (temp == NULL)
					ft_lstclear(&ennemi);
				ft_lstadd_back(&ennemi, temp);
			}
		}
		i = 0;
		j++;
	}
	return (ennemi);
}
