/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:49 by lribette          #+#    #+#             */
/*   Updated: 2024/01/05 18:04:13 by lribette         ###   ########.fr       */
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
	mlx_loop(window->mlx);
	//map->length * 32
	
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
	//img = mlx_xpm_file_to_image(window->mlx, "./assets/R5-D4.xpm", &img_size, &img_size);
	//mlx_put_image_to_window(window->mlx, window->win, img, 0, 0);
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
}