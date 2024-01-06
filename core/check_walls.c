/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:01:20 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:26:01 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i][j])
	{
		if (game->map.map[i][j] != '1')
			ft_free_error(game, "Not closed");
		j++;
	}
	i++;
	while (game->map.map[i] && game->map.map[i + 1])
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][game->map.length - 1] != '1')
			ft_free_error(game, "Not closed");
		i++;
	}
	j = 0;
	while (game->map.map[i][j])
	{
		if (game->map.map[i][j] != '1')
			ft_free_error(game, "Not closed");
		j++;
	}
}

void	where_p(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[x][y])
	{
		y++;
		if (!game->map.map[x][y + 1])
		{
			y = 0;
			x++;
		}
		if (game->map.map[x][y] == 'P')
			break ;
	}
	game->player.x = x;
	game->player.y = y;
}

static int	is_checked(char c)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	return (1);
}

static void	check_elements(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == '0')
		game->map.map[x][y] = 'o';
	else if (game->map.map[x][y] == 'C')
		game->map.map[x][y] = 'c';
	else if (game->map.map[x][y] == 'E')
		game->map.map[x][y] = 'e';
	else if (game->map.map[x][y] == 'P')
		game->map.map[x][y] = 'p';
	if (!is_checked(game->map.map[x][y + 1]))
		check_elements(game, x, y + 1);
	if (!is_checked(game->map.map[x][y - 1]))
		check_elements(game, x, y - 1);
	if (!is_checked(game->map.map[x + 1][y]))
		check_elements(game, x + 1, y);
	if (!is_checked(game->map.map[x - 1][y]))
		check_elements(game, x - 1, y);
}

void	is_possible(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_elements(game, game->player.x, game->player.y);
	while (game->map.map[x])
	{
		y = 0;
		while (game->map.map[x][y])
		{
			if (!is_checked(game->map.map[x][y]))
				ft_free_error(game, "Impossible path");
			y++;
		}
		ft_printf("%s\n", game->map.map[x]);
		x++;
	}
	
}