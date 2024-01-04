/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:01:20 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 12:01:50 by lribette         ###   ########.fr       */
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
