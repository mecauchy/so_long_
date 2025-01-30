/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:43 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/30 18:23:47 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map(t_list *lst)
{
	lst->img_wall = mlx_xpm_file_to_image(lst->mlx, "../textures/img_wall.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_coin = mlx_xpm_file_to_image(lst->mlx, "../textures/img_coin.xpm" ,lst->img_longueur, lst->img_largeur);
	lst->img_exit = mlx_xpm_file_to_image(lst->mlx, "../textures/img_exit.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_floor = mlx_xpm_file_to_image(lst->mlx, "../textures/img_floor.xpm", lst->img_longueur, lst->img_largeur);
	lst->img_perso = mlx_xpm_file_to_image(lst->mlx, player_move(lst), lst->img_longueur, lst->img_largeur);
	if (!lst->img_wall || !lst->img_coin || !lst->img_exit || !lst->img_floor || !lst->img_perso)
	{
		ft_printf("Error when creating map");
		exit(1);
	}
}

int	largeur_map_size(t_list *lst)
{
	char	*line;
	int	count;
	
	count = 0;
	line = get_next_line(lst->file);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(lst->file);
	}
	free(line);
	close(lst->file);
	return (count);
}

void	size_map(t_list *lst)
{
	// int	file;
	
	// file = open("../map_ber/map01.ber", O_RDONLY);
	lst->largeur_map = largeur_map_size(lst);
	lst->longueur_map = ft_strlen();
}

void	check_corner(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lst->map[0][i] < lst->longueur_map && lst->map[0][i] == '1')
		i++;
	while (lst->map[j][0] < lst->largeur_map && lst->map[j][0] == 1)
		j++;
	if (i != lst->longueur_map || j != lst->largeur_map)
	{
		ft_putendl_fd("error : invalid map", 2);
		exit(0);
	}
}

char	*player_move(t_list *lst)
{
	if (lst->keycode == UP || lst->keycode == W)
		return ("../textures/img_perso_up.xpm");
	if (lst->keycode == DOWN || lst->keycode == S)
		return ("../textures/img_perso_down.xpm");
	if (lst->keycode == LEFT || lst->keycode == A)
		return ("../textures/img_perso_left.xpm");
	if (lst->keycode == RIGHT || lst->keycode == D)
		return ("../textures/img_perso_left.xpm");
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

void	parsing(t_list *lst)
{
	check_corner(lst);
	fill_map();
	draw_map();
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("error : arguments", 2);
		exit(1);
	init_lst();
	parsing();
	
}

// lst.format_longueur ==== 45 (taille rendu)
// lst.format_largeur ==== 45 (taille rendu)