/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:49 by lribette          #+#    #+#             */
/*   Updated: 2024/01/05 23:13:36 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_window(t_elements *map, t_player *player, t_vars *window)
{
	(void)player;
	window->mlx = mlx_init();
	ft_printf("height %d, length %d", map->height, map->length);
	window->win = mlx_new_window(window->mlx, map->length * 32, map->height * 32, "So_long");
	set_images(map, player, window);
	mlx_hook(window.win, 17, 1L << 2, destroy_window, &window);
	mlx_loop(window->mlx);
	}

void	set_images(t_elements *map, t_player *player, t_vars *window)
{
	(void)player;
	(void)map;
	int		x;
	int		y;
	//void	*img;
	//int		img_size;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			ft_printf("x : %d, y : %d, map->map[x][y] : %c\n", x, y, map->map[y][x]);
			display_item(window, map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	/*if ()
		mlx_destroy_window(window->mlx, window->win);*/
}

int	destroy_window(t_elements *map)
{
	free_map(map);
}