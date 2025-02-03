/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:29:15 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:30 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_window(t_list *lst)
{
	mlx_clear_window(lst->mlx, lst->window);
	create_map(lst);
}

void	exit_game(t_list *lst, int value)
{
	if (value)
		ft_printf("you won the game after %d moves, congratulations!", lst->move);
	else
		ft_printf("Sortie du jeu ...");
	if (lst->img_exit)
		mlx_destroy_image(lst->mlx, lst->img_exit);
	if (lst->img_floor)
		mlx_destroy_image(lst->mlx, lst->img_floor);
	if (lst->img_perso)
		mlx_destroy_image(lst->mlx, lst->img_perso);
	if (lst->img_wall)
		mlx_destroy_image(lst->mlx, lst->img_wall);
	if (lst->window)
		mlx_destroy_window(lst->mlx, lst->window);
	mlx_destroy_display(lst->mlx);
	free(lst->mlx);
	exit(0);
}