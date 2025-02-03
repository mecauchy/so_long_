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
			if (lst->map[x][y] != '1' && lst->map[x][y] != '0' && lst->map[x][y] != 'P' && lst->map[x][y] != 'C' && lst->map[x][y] != 'E')
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

int	stock_map(t_list *lst)
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
	lst->largeur_map = largeur_map_size(lst);
	lst->longueur_map = ft_strlen();
	close(lst->file);
	return (count);
}

void	parsing(t_list *lst)
{
	check_file(lst);
	check_valide_map(lst);
	check_corner(lst);
	fill_map(lst);
	stock_map(lst);
}