/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:01:20 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 21:28:46 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_closed(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map.map[i][j])
	{
		if (g->map.map[i][j] != '1')
			ft_free_error(g, "Not closed");
		j++;
	}
	i++;
	while (g->map.map[i] && g->map.map[i + 1])
	{
		if (g->map.map[i][0] != '1' || g->map.map[i][g->map.length - 1] != '1')
			ft_free_error(g, "Not closed");
		i++;
	}
	j = 0;
	while (g->map.map[i][j])
	{
		if (g->map.map[i][j] != '1')
			ft_free_error(g, "Not closed");
		j++;
	}
}

void	where_p(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map.map[y][x])
	{
		x++;
		if (!g->map.map[y][x + 1])
		{
			x = 0;
			y++;
		}
		if (g->map.map[y][x] == 'P')
			break ;
	}
	g->player.x = x;
	g->player.y = y;
}

static int	is_checked(char c)
{
	if (c == '0' || c == 'C' || c == 'P')
		return (0);
	return (1);
}

static void	check_elements(t_game *g, int y, int x)
{
	if (g->map.map[y][x] == '0')
		g->map.map[y][x] = 'o';
	else if (g->map.map[y][x] == 'C')
		g->map.map[y][x] = 'c';
	else if (g->map.map[y][x] == 'E')
		g->map.map[y][x] = 'e';
	else if (g->map.map[y][x] == 'P')
		g->map.map[y][x] = 'p';
	if (!is_checked(g->map.map[y][x + 1]))
		check_elements(g, y, x + 1);
	if (!is_checked(g->map.map[y][x - 1]))
		check_elements(g, y, x - 1);
	if (!is_checked(g->map.map[y + 1][x]))
		check_elements(g, y + 1, x);
	if (!is_checked(g->map.map[y - 1][x]))
		check_elements(g, y - 1, x);
}

void	is_possible(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_elements(g, g->player.y, g->player.x);
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (!is_checked(g->map.map[y][x]) && g->map.map[y][x] != 'E')
				ft_free_error(g, "Impossible path");
			x++;
		}
		y++;
	}
	display_exit(g);
}
