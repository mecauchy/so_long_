/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:29:15 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 12:43:47 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_window(t_list *lst)
{
	mlx_clear_window(lst->mlx, lst->window);
	create_map(lst);
}

void	free_map(t_list *lst)
{
	int	i;
	i = 0;
	while (lst->map[i])
	{
		free(lst->map[i]);
		i++;
	}
	free(lst->map);
}

void	error_game(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}
