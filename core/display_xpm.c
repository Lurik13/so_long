/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:43:53 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:11:31 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_item(t_game *game, char c, int x, int y)
{
	if (c == 'o')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.ground, x * 32, y * 32);
	else if (c == '1')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.wall, x * 32, y * 32);
	else if (c == 'e')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.blocked_exit, x * 32, y * 32);
	else if (c == '3')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_3, x * 32, y * 32);
	else if (c == 'B')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_b, x * 32, y * 32);
	else if (c == 'D')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_d, x * 32, y * 32);
	else if (c == 'U')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_u, x * 32, y * 32);
	else if (c == 'G')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_g, x * 32, y * 32);
	else if (c == 'I')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_i, x * 32, y * 32);
	else if (c == 'R')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_r, x * 32, y * 32);
	else if (c == '5')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_5, x * 32, y * 32);
	else if (c == 'p')
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.collec_p, x * 32, y * 32);
	else //iciiiiiiiiii
		mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.opened_exit, x * 32, y * 32);
}

void	set_xpm(t_game *game)
{
	int	size;
	
	size = 32;
	game->window.ground = mlx_xpm_file_to_image(game->window.mlx, "./assets/Ground.xpm", &size, &size);
	game->window.wall = mlx_xpm_file_to_image(game->window.mlx, "./assets/Wall.xpm", &size, &size);
	game->window.blocked_exit = mlx_xpm_file_to_image(game->window.mlx, "./assets/Blocked_Exit.xpm", &size, &size);
	game->window.opened_exit = mlx_xpm_file_to_image(game->window.mlx, "./assets/Opened_Exit.xpm", &size, &size);
	game->window.collec_3 = mlx_xpm_file_to_image(game->window.mlx, "./assets/11-3K.xpm", &size, &size);
	game->window.collec_b = mlx_xpm_file_to_image(game->window.mlx, "./assets/B1.xpm", &size, &size);
	game->window.collec_u = mlx_xpm_file_to_image(game->window.mlx, "./assets/DUM.xpm", &size, &size);
	game->window.collec_g = mlx_xpm_file_to_image(game->window.mlx, "./assets/GNK.xpm", &size, &size);
	game->window.collec_d = mlx_xpm_file_to_image(game->window.mlx, "./assets/Droideka.xpm", &size, &size);
	game->window.collec_i = mlx_xpm_file_to_image(game->window.mlx, "./assets/IG-88.xpm", &size, &size);
	game->window.collec_r = mlx_xpm_file_to_image(game->window.mlx, "./assets/R2-D2.xpm", &size, &size);
	game->window.collec_5 = mlx_xpm_file_to_image(game->window.mlx, "./assets/R5-D4.xpm", &size, &size);
	game->window.collec_p = mlx_xpm_file_to_image(game->window.mlx, "./assets/Jawa.xpm", &size, &size);
}
