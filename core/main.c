/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/05 23:12:41 by lribette         ###   ########.fr       */
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

int	free_map(t_elements *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	return (0);
}

void	ft_free_error(t_elements *map, char *str)
{
	free_map(map);
	ft_error(str);
}

/*static int	close_window(t_vars *window)
{
	mlx_destroy_window(window->mlx, window->win);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_elements	map;
	t_player	player;
	t_vars		window;

	map.map = NULL;
	player.x = 0;
	player.y = 0;
	//window.mlx = NULL;
	if (argc != 2)
		ft_error("You need to include a .ber file");
	init_map(&map, &player, argv[1]);
	set_window(&map, &player, &window);
}
