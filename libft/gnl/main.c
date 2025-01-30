/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:19:31 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/30 15:13:12 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tester.txt", O_RDONLY);
	i = 1;
	while (i <= 50)
	{
		line = get_next_line(fd1);
		// printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
