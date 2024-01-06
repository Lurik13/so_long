/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:26:37 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 19:02:47 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	can_move(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == '1' || g->map.map[y][x] == 'e')
		return (0);
	return (1);
}

void	to_left(t_game *g)
{
	if (can_move(g, g->player.y, g->player.x - 1))
	{
		if (g->map.map[g->player.y][g->player.x - 1] != 'o'
			&& g->map.map[g->player.y][g->player.x - 1] != '1')
			g->map.nb_of_collectibles--;
		if (g->map.map[g->player.y][g->player.x - 1] == 'E')
			the_end(g, g->player.y * 32, g->player.x * 32);
		g->map.map[g->player.y][g->player.x - 1] = 'p';
		g->map.map[g->player.y][g->player.x] = 'o';
		display_item(g, 'p', g->player.x * 32 - 32, g->player.y * 32);
		display_item(g, 'o', g->player.x * 32, g->player.y * 32);
		g->player.x--;
	}
}

void	to_up(t_game *g)
{
	if (can_move(g, g->player.y - 1, g->player.x))
	{
		if (g->map.map[g->player.y - 1][g->player.x] != 'o'
			&& g->map.map[g->player.y - 1][g->player.x] != '1')
			g->map.nb_of_collectibles--;
		if (g->map.map[g->player.y - 1][g->player.x] == 'E')
			the_end(g, g->player.y * 32, g->player.x * 32);
		g->map.map[g->player.y - 1][g->player.x] = 'p';
		g->map.map[g->player.y][g->player.x] = 'o';
		display_item(g, 'p', g->player.x * 32, g->player.y * 32 - 32);
		display_item(g, 'o', g->player.x * 32, g->player.y * 32);
		g->player.y--;
	}
}

void	to_right(t_game *g)
{
	if (can_move(g, g->player.y, g->player.x + 1))
	{
		if (g->map.map[g->player.y][g->player.x + 1] != 'o'
			&& g->map.map[g->player.y][g->player.x + 1] != '1')
			g->map.nb_of_collectibles--;
		if (g->map.map[g->player.y][g->player.x + 1] == 'E')
			the_end(g, g->player.y * 32, g->player.x * 32);
		g->map.map[g->player.y][g->player.x + 1] = 'p';
		g->map.map[g->player.y][g->player.x] = 'o';
		display_item(g, 'p', g->player.x * 32 + 32, g->player.y * 32);
		display_item(g, 'o', g->player.x * 32, g->player.y * 32);
		g->player.x++;
	}
}

void	to_down(t_game *g)
{
	if (can_move(g, g->player.y + 1, g->player.x))
	{
		if (g->map.map[g->player.y + 1][g->player.x] != 'o'
			&& g->map.map[g->player.y + 1][g->player.x] != '1')
			g->map.nb_of_collectibles--;
		if (g->map.map[g->player.y + 1][g->player.x] == 'E')
			the_end(g, g->player.y * 32, g->player.x * 32);
		g->map.map[g->player.y + 1][g->player.x] = 'p';
		g->map.map[g->player.y][g->player.x] = 'o';
		display_item(g, 'p', g->player.x * 32, g->player.y * 32 + 32);
		display_item(g, 'o', g->player.x * 32, g->player.y * 32);
		g->player.y++;
	}
}
