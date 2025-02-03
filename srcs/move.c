/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:47 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/03 13:50:03 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_list *lst)
{
	if (lst->map[lst->y - 1][lst->x] != '1')
	{
		if (lst->map[lst->y - 1][lst->x] == 'C')
		{
			lst->map[lst->y - 1][lst->x] = 'P';
			lst->nb_collectibles--;
		}
		if (lst->map[lst->y - 1][lst->x] == 'E')
		{
			if (lst->nb_collectibles == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y - 1][lst->x] == '0')
			lst->map[lst->y - 1][lst->x] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_down(t_list *lst)
{
	if (lst->map[lst->y + 1][lst->x] != '1')
	{
		if (lst->map[lst->y + 1][lst->x] == 'C')
		{
			lst->map[lst->y + 1][lst->x] == 'P';
			lst->nb_collectibles--;
		}
		if (lst->map[lst->y + 1][lst->x] == 'E')
		{
			if (lst->nb_collectibles == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y + 1][lst->x] == '0')
			lst->map[lst->y + 1][lst->x] = 'P';
		lst->map[lst->x][lst->y] == '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_left(t_list *lst)
{
	if (lst->map[lst->y][lst->x - 1] != '1')
	{
		if (lst->map[lst->y][lst->x - 1] == 'C')
		{
			lst->map[lst->y][lst->x - 1] = 'P';
			lst->nb_collectibles--;
		}
		if (lst->map[lst->y][lst->x - 1] == 'E')
		{
			if (lst->nb_collectibles == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y][lst->x - 1] == '0')
			lst->map[lst->y][lst->x - 1] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_right(t_list *lst)
{
	if (lst->map[lst->y][lst->x + 1] != '1')
	{
		if (lst->map[lst->y][lst->x + 1] == 'C')
		{
			lst->map[lst->y][lst->x + 1] == 'P';
			lst->nb_collectibles--;
		}
		if (lst->map[lst->y][lst->x + 1] == 'E')
		{
			if (lst->nb_collectibles == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y][lst->x + 1] == '0')
			lst->map[lst->y][lst->x + 1] = 'P';
		lst->map[lst->y][lst->x] == '0';
		lst->move++;
		update_window(lst);
	}
}
