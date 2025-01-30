/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:39:17 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/30 18:14:14 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define W 119
# define A 97
# define S 115
# define D 100

# define ESC 65307

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>


typedef	struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_down;
}				t_img;

typedef	struct s_map
{
	unsigned int	nb_coin;
	unsigned int	nb_exit;	
	unsigned int	nb_player;
	unsigned int	nb_collectible;
}				t_map;

typedef	struct s_list
{
	void	*img;
	void	*mlx;
	char	**map;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_perso;
	void	*img_coin;
	int		longueur_map;
	int		largeur_map;
	int		img_longueur;
	int		img_largeur;
	int		keycode;
	int		move;
	int		file;
}				t_list;



#endif