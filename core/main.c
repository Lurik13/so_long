/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 14:49:47 by lribette         ###   ########.fr       */
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

int	free_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.height)
	{
		free(g->map.map[i]);
		i++;
	}
	free(g->map.map);
	return (0);
}

void	ft_free_error(t_game *g, char *str)
{
	free_map(g);
	ft_error(str);
}

/*static int	close_window(t_vars *window)
{
	mlx_destroy_window(g->win.mlx, g->win.win);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_game		g;

	g.map.map = NULL;
	g.player.x = 0;
	g.player.y = 0;
	//window.mlx = NULL;
	if (argc != 2)
		ft_error("You need to include a .ber file");
	init_map(&g, argv[1]);
	set_window(&g);
}
