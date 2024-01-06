/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:00:14 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:24:39 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sort_elements(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			game->map.nb_of_void++;
		else if (str[i] == '1')
			game->map.nb_of_walls++;
		else if (str[i] == 'C')
			game->map.nb_of_collectibles++;
		else if (str[i] == 'E')
			game->map.nb_of_exits++;
		else if (str[i] == 'P')
			game->map.nb_of_starts++;
		else
			ft_free_error(game, "Wrong symbol");
		i++;
	}
}

void	check_number_of_elems(t_game *game)
{
	int	i;

	game->map.nb_of_void = 0;
	game->map.nb_of_walls = 0;
	game->map.nb_of_collectibles = 0;
	game->map.nb_of_exits = 0;
	game->map.nb_of_starts = 0;
	i = 0;
	while (game->map.map[i])
	{
		sort_elements(game, game->map.map[i]);
		i++;
	}
	if (game->map.nb_of_collectibles < 1)
		ft_free_error(game, "It requires at least one collectible");
	if (game->map.nb_of_exits != 1)
		ft_free_error(game, "It requires one exit");
	if (game->map.nb_of_starts != 1)
		ft_free_error(game, "It requires one start position");
}
