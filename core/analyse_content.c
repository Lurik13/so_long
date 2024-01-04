/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:00:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 12:01:54 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sort_elements(t_elements *map, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			map->nb_of_void++;
		else if (str[i] == '1')
			map->nb_of_walls++;
		else if (str[i] == 'C')
			map->nb_of_collectibles++;
		else if (str[i] == 'E')
			map->nb_of_exits++;
		else if (str[i] == 'P')
			map->nb_of_starts++;
		else
			ft_free_error(map, "Wrong symbol");
		i++;
	}
}

void	check_number_of_elems(t_elements *map)
{
	int	i;

	map->nb_of_void = 0;
	map->nb_of_walls = 0;
	map->nb_of_collectibles = 0;
	map->nb_of_exits = 0;
	map->nb_of_starts = 0;
	i = 0;
	while (map->map[i])
	{
		sort_elements(map, map->map[i]);
		i++;
	}
	if (map->nb_of_collectibles < 1)
		ft_free_error(map, "It requires at least one collectible");
	if (map->nb_of_exits != 1)
		ft_free_error(map, "It requires an exit");
	if (map->nb_of_starts != 1)
		ft_free_error(map, "It requires a start position");
}
