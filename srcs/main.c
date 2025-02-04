/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:43 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/04 19:32:01 by mecauchy         ###   ########.fr       */
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
		return ("../textures/player_right.xpm");
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
	mlx_string_put(lst->mlx, lst->window, 10, 10, 0xFFFFFF, "Press ESC to quit");
	mlx_string_put(lst->mlx, lst->window, 10, 30, 0xFF0099, ft_strjoin("steps : ", ft_itoa(lst->move)));
}

int	key_press(t_list *lst)
{
	if (lst->keycode == ESC)
		exit(1);
	if (lst->keycode == UP || lst->keycode == W)
		move_up(lst);
	if (lst->keycode == DOWN || lst->keycode == S)
		move_down(lst);
	if (lst->keycode == LEFT || lst->keycode == A)
		move_left(lst);
	if (lst->keycode == RIGHT || lst->keycode == D)
		move_right(lst);
	return (0);
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

void	init_game(t_list *lst)
{
	lst->window = NULL;
	lst->map = NULL;
	lst->img_wall = NULL;
	lst->img_exit = NULL;
	lst->img_coin = NULL;
	lst->img_perso = NULL;
	lst->img_floor = NULL;
	lst->path = NULL;
	lst->img_longueur = 32;
	lst->img_largeur = 32;
	lst->longueur_map = 0;
	lst->largeur_map = 0;
	lst->keycode = 0;
	lst->move = 0;
	lst->x = 0;
	lst->y = 0;
	lst->map_info.nb_coin = 0;
	lst->map_info.nb_exit = 0;
	lst->map_info.nb_player = 0;
	lst->map_info.nb_collectible = 0;
	lst->player.player_up = NULL;
	lst->player.player_down = NULL;
	lst->player.player_left = NULL;
	lst->player.player_right = NULL;
}

int	main(int ac, char **av)
{
	t_list	lst;
	
	if (ac != 2)
	{
		ft_putendl("error : arguments", 2);
		exit(1);
	}
	lst.path = av[1];
	lst.fd = open(lst.path, O_RDONLY);
	if (lst.fd < 0)
	{
		ft_putendl("error : can't open file", 2);
		exit(1);
	}
	parsing(&lst);
	init_game(&lst);
	lst.mlx = mlx_init();
	if (!lst.mlx)
	{
		ft_putendl("error : mlx_init", 2);
		exit(1);
	}
	lst.window = mlx_new_window(lst.mlx, lst.largeur_map * 32, lst.longueur_map * 32, "so_long");
	create_map(&lst);
	mlx_hook(lst.window, EXIT_CODE, 0, exit_game, &lst);
	mlx_key_hook(lst.window, key_press, &lst);
	mlx_loop(lst.mlx);
	return (0);
}
// lst.format_longueur ==== 32 (taille rendu)
// lst.format_largeur ==== 32 (taille rendu)