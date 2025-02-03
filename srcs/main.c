/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:43 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/03 12:40:11 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*player_move(t_list *lst)
{
	if (lst->keycode == UP || lst->keycode == W)
		return ("../textures/player_up.xpm");
	if (lst->keycode == DOWN || lst->keycode == S)
		return ("../textures/player_down.xpm");
	if (lst->keycode == LEFT || lst->keycode == A)
		return ("../textures/player_left.xpm");
	if (lst->keycode == RIGHT || lst->keycode == D)
		return ("../textures/player_down.xpm");
}

void	assign_map(t_list *lst)
{
	lst->img_wall = mlx_xpm_file_to_image(lst->mlx, "../textures/wall.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_coin = mlx_xpm_file_to_image(lst->mlx, "../textures/collectible.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_exit = mlx_xpm_file_to_image(lst->mlx, "../textures/img_exit.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_floor = mlx_xpm_file_to_image(lst->mlx, "../textures/floor.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_perso = mlx_xpm_file_to_image(lst->mlx, player_move(lst), lst->img_longueur, lst->img_largeur);
	if (!lst->img_wall || !lst->img_coin || !lst->img_exit || !lst->img_floor || !lst->img_perso)
	{
		ft_printf("Error when creating map");
		exit(1);
	}
}

void	create_map(t_list *lst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < lst->largeur_map)
	{
		x = 0;
		while (x < lst->longueur_map)
		{
			if (lst->map[y][x] == '1')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_wall, lst->img_longueur, lst->img_largeur);
			if (lst->map[y][x] == '0')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_floor, lst->img_longueur, lst->img_largeur);
			if (lst->map[y][x] == 'C')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_coin, lst->img_longueur, lst->img_largeur);
			if (lst->map[y][x] == 'E')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_exit, lst->img_longueur, lst->img_largeur);
			if (lst->map[y][x] == 'P')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_perso, lst->img_longueur, lst->img_largeur);
			x++;
		}
		y++;
	}
}

int	key_press(t_list *lst)
{
	if (lst->keycode == ESC)
		exit(1);
	if (lst->keycode == UP || lst->keycode == W)
		move_up(lst);
	if (lst->keycode == DOWN || lst->keycode == S)
		move_down(lst);
	if (lst->keycode == RIGHT || lst->keycode == D)
		move_right(lst);
	if (lst->keycode == LEFT || lst->keycode == A)
		move_left(lst);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("error : arguments", 2);
		exit(1);
	}
	parsing();
	init_lst();
}

// lst.format_longueur ==== 32 (taille rendu)
// lst.format_largeur ==== 32 (taille rendu)