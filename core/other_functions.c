/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:33:58 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 19:37:20 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_exit(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == 'E')
			{
				g->map.map[y][x] = 'e';
				x = g->map.length - 1;
				y = g->map.height - 1;
			}
			x++;
		}
		y++;
	}
}

void	open_exit(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == 'e')
			{
				g->map.map[y][x] = 'E';
				x *= 32;
				y *= 32;
				mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.o_e, x, y);
				x = g->map.length - 1;
				y = g->map.height - 1;
			}
			x++;
		}
		y++;
	}
}
