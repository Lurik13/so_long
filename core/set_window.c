/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:49 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 15:09:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_window(t_game *g)
{
	int	len;
	int	hei;

	len = g->map.length * 32;
	hei = g->map.height * 32;
	g->win.mlx = mlx_init();
	ft_printf("height %d, length %d", g->map.height, g->map.length);
	g->win.win = mlx_new_window(g->win.mlx, len, hei, "So_long");
	which_collectible(g);
	set_xpm(g);
	set_images(g);
	mlx_hook(g->win.win, 17, 1L << 2, ft_destroy_window, g);
	mlx_hook(g->win.win, 2, 1L << 0, ft_check_key, g);
	mlx_loop(g->win.mlx);
}

void	set_images(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.length)
		{
			ft_printf("x : %d, y : %d, g->map.map[x][y] : %c\n", x, y, g->map.map[y][x]);
			display_item(g, g->map.map[y][x], x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	ft_check_key(int keycode, t_game *g)
{
	if (keycode == 65307)
		ft_destroy_window(g);
	return (0);
}

int	ft_destroy_window(t_game *g)
{
	mlx_destroy_window(g->win.mlx, g->win.win);
	mlx_destroy_image(g->win.mlx, g->win.g);
	mlx_destroy_image(g->win.mlx, g->win.w);
	mlx_destroy_image(g->win.mlx, g->win.b_e);
	mlx_destroy_image(g->win.mlx, g->win.o_e);
	mlx_destroy_image(g->win.mlx, g->win.c_3);
	mlx_destroy_image(g->win.mlx, g->win.c_b);
	mlx_destroy_image(g->win.mlx, g->win.c_u);
	mlx_destroy_image(g->win.mlx, g->win.c_g);
	mlx_destroy_image(g->win.mlx, g->win.c_d);
	mlx_destroy_image(g->win.mlx, g->win.c_i);
	mlx_destroy_image(g->win.mlx, g->win.c_r);
	mlx_destroy_image(g->win.mlx, g->win.c_5);
	mlx_destroy_image(g->win.mlx, g->win.c_p);
	mlx_destroy_display(g->win.mlx);
	free(g->win.mlx);
	free_map(g);
	exit(0);
}
