/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:01:20 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 15:53:23 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_closed(t_elements *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			ft_free_error(map, "Not closed");
		j++;
	}
	i++;
	while (map->map[i] && map->map[i + 1])
	{
		if (map->map[i][0] != '1' || map->map[i][map->length - 1] != '1')
			ft_free_error(map, "Not closed");
		i++;
	}
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			ft_free_error(map, "Not closed");
		j++;
	}
}

void	where_p(t_elements *map, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[x][y])
	{
		y++;
		if (!map->map[x][y + 1])
		{
			y = 0;
			x++;
		}
		if (map->map[x][y] == 'P')
			break ;
	}
	player->x = x;
	player->y = y;
}

static int	is_checked(char c)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	return (1);
}

static void	check_elements(t_elements *map, int x, int y)
{
	if (map->map[x][y] == '0')
		map->map[x][y] = 'o';
	else if (map->map[x][y] == 'C')
		map->map[x][y] = 'c';
	else if (map->map[x][y] == 'E')
		map->map[x][y] = 'e';
	else if (map->map[x][y] == 'P')
		map->map[x][y] = 'p';
	if (!is_checked(map->map[x][y + 1]))
		check_elements(map, x, y + 1);
	if (!is_checked(map->map[x][y - 1]))
		check_elements(map, x, y - 1);
	if (!is_checked(map->map[x + 1][y]))
		check_elements(map, x + 1, y);
	if (!is_checked(map->map[x - 1][y]))
		check_elements(map, x - 1, y);
}

void	is_possible(t_elements *map, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_elements(map, player->x, player->y);
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (!is_checked(map->map[x][y]))
				ft_free_error(map, "Impossible path");
			y++;
		}
		ft_printf("%s\n", map->map[x]);
		x++;
	}
	
}