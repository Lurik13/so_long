/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:01:20 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 15:07:53 by lribette         ###   ########.fr       */
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
	while (g->map.map[x][y])
	{
		y++;
		if (!g->map.map[x][y + 1])
		{
			y = 0;
			x++;
		}
		if (g->map.map[x][y] == 'P')
			break ;
	}
	g->player.x = x;
	g->player.y = y;
}

static int	is_checked(char c)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	return (1);
}

static void	check_elements(t_game *g, int x, int y)
{
	if (g->map.map[x][y] == '0')
		g->map.map[x][y] = 'o';
	else if (g->map.map[x][y] == 'C')
		g->map.map[x][y] = 'c';
	else if (g->map.map[x][y] == 'E')
		g->map.map[x][y] = 'e';
	else if (g->map.map[x][y] == 'P')
		g->map.map[x][y] = 'p';
	if (!is_checked(g->map.map[x][y + 1]))
		check_elements(g, x, y + 1);
	if (!is_checked(g->map.map[x][y - 1]))
		check_elements(g, x, y - 1);
	if (!is_checked(g->map.map[x + 1][y]))
		check_elements(g, x + 1, y);
	if (!is_checked(g->map.map[x - 1][y]))
		check_elements(g, x - 1, y);
}

void	is_possible(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_elements(g, g->player.x, g->player.y);
	while (g->map.map[x])
	{
		y = 0;
		while (g->map.map[x][y])
		{
			if (!is_checked(g->map.map[x][y]))
				ft_free_error(g, "Impossible path");
			y++;
		}
		ft_printf("%s\n", g->map.map[x]);
		x++;
	}
}
