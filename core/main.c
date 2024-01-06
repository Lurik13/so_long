/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:29:57 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	int	i;

	i = -1;
	write(1, "Error\n", 6);
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	exit(1);
}

int	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	return (0);
}

void	ft_free_error(t_game *game, char *str)
{
	free_map(game);
	ft_error(str);
}

/*static int	close_window(t_vars *window)
{
	mlx_destroy_window(game->window.mlx, game->window.win);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_game		game;

	game.map.map = NULL;
	game.player.x = 0;
	game.player.y = 0;
	//window.mlx = NULL;
	if (argc != 2)
		ft_error("You need to include a .ber file");
	init_map(&game, argv[1]);
	set_window(&game);
}
