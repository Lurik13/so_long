/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:49 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:53:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_window(t_game *game)
{
	game->window.mlx = mlx_init();
	ft_printf("height %d, length %d", game->map.height, game->map.length);
	game->window.win = mlx_new_window(game->window.mlx, game->map.length * 32, game->map.height * 32, "So_long");
	set_xpm(game);
	set_images(game);
	mlx_hook(game->window.win, 17, 1L << 2, ft_destroy_window, game);
	//mlx_hook(game->window.win, 2, 1L << 0, check_key, game);
	mlx_loop(game->window.mlx);
	}

void	set_images(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.length)
		{
			ft_printf("x : %d, y : %d, game->map.map[x][y] : %c\n", x, y, game->map.map[y][x]);
			display_item(game, game->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
	/*if ()
		mlx_destroy_window(game->window.mlx, game->window.win);*/
}

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	mlx_destroy_image(game->window.mlx, game->window.ground);
	mlx_destroy_image(game->window.mlx, game->window.wall);
	mlx_destroy_image(game->window.mlx, game->window.blocked_exit);
	mlx_destroy_image(game->window.mlx, game->window.opened_exit);
	mlx_destroy_image(game->window.mlx, game->window.collec_3);
	mlx_destroy_image(game->window.mlx, game->window.collec_b);
	mlx_destroy_image(game->window.mlx, game->window.collec_u);
	mlx_destroy_image(game->window.mlx, game->window.collec_g);
	mlx_destroy_image(game->window.mlx, game->window.collec_d);
	mlx_destroy_image(game->window.mlx, game->window.collec_i);
	mlx_destroy_image(game->window.mlx, game->window.collec_r);
	mlx_destroy_image(game->window.mlx, game->window.collec_5);
	mlx_destroy_image(game->window.mlx, game->window.collec_p);
	mlx_destroy_display(game->window.mlx);
	free(game->window.mlx);
	free_map(game);
	exit(0);
}