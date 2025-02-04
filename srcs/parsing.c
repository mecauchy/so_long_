/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:48:45 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/04 19:31:38 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_valide_map(t_list *lst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (lst->map[y])
	{
		x = 0;
		while (lst->map[x][y])
		{
			if (lst->map[x][y] != '1' && lst->map[x][y] != '0' &&
				lst->map[x][y] != 'P' && lst->map[x][y] != 'C' &&
				lst->map[x][y] != 'E')
			{
				ft_putendl_fd("Error : invalid map", 2);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	check_file(t_list *lst)
{
	int	file;

	file = open("../map_ber/map01.ber", O_RDONLY);
	if (file < 0)
	{
		ft_putendl_fd("Error : can't open file", 2);
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 4) != 0)
	{
		ft_putendl_fd("Error : invalid file", 2);
		exit(1);
	}
}

void	stock_map(t_list *lst)
{
	char	*line;
	
	lst->file = open(lst->path, O_RDONLY);
	if (lst->file < 0)
		return ;
	line = get_next_line(lst->file);
	if (!line)
		return ;
	lst->stock = ft_strdup("");
	while (line)
	{
		lst->stock = ft_strjoin(lst->stock, line);
		free(line);
		line = get_next_line(lst->file);
	}
	lst->map = ft_split(lst->stock, '\n');
	free(lst->stock);
	close(lst->file);
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
		exit(1);
	}
}

void	fill_mapinfo(t_list *lst)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < lst->largeur_map)
	{
		while (x < lst->longueur_map)
		{
			if (lst->map[y][x] == 'P')
			{
				lst->x = y;
				lst->y = x;
				lst->map_info.nb_player++;
			}
			if (lst->map[y][x] == 'C')
				lst->map_info.nb_collectible++;
			if (lst->map[y][x] == 'E')
				lst->map_info.nb_exit++;
			x++;
		}
		x = 0;
		y++;
	}
}

unsigned int	size_map(t_list *lst)
{
	char	*line;
	int		count;

	count = 0;
	lst->fd = open(lst->path, O_RDONLY);
	if (lst->fd < 0)
		return (0);
	line = get_next_line(lst->fd);
	lst->longueur_map = ft_strlen(line - 1);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(lst->fd);
	}
	free(line);
	lst->largeur_map = largeur_map_size(lst);
	close(lst->fd);
	return (count);
}

void	parsing(t_list *lst)
{
	check_file(lst);
	stock_map(lst);
	check_valide_map(lst);
	check_corner(lst);
	size_map(lst);
	fill_mapinfo(lst);
}
