/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:00:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 18:23:05 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sort_elements(t_game *g, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			g->map.nb_of_void++;
		else if (str[i] == '1')
			g->map.nb_of_walls++;
		else if (str[i] == 'C')
			g->map.nb_of_collectibles++;
		else if (str[i] == 'E')
			g->map.nb_of_exits++;
		else if (str[i] == 'P')
			g->map.nb_of_starts++;
		else
			ft_free_error(g, "Wrong symbol");
		i++;
	}
}

void	check_number_of_elems(t_game *g)
{
	int	i;

	g->map.nb_of_void = 0;
	g->map.nb_of_walls = 0;
	g->map.nb_of_collectibles = 0;
	g->map.nb_of_exits = 0;
	g->map.nb_of_starts = 0;
	i = 0;
	while (g->map.map[i])
	{
		sort_elements(g, g->map.map[i]);
		i++;
	}
	if (g->map.nb_of_collectibles < 1)
		ft_free_error(g, "It requires at least one collectible");
	if (g->map.nb_of_exits != 1)
		ft_free_error(g, "It requires one exit");
	if (g->map.nb_of_starts != 1)
		ft_free_error(g, "It requires one start position");
}
