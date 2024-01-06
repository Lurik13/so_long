/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:52 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:29:24 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(t_game *game, char *s, char *str)
{
	int		i;

	i = 0;
	str = malloc((game->map.length + 1) * sizeof(char));
	if (!str)
		ft_error("Malloc failed");
	while (i < game->map.length)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

void	map_copy(t_game *game, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	game->map.map = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.map)
		ft_error("Malloc failed");
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = ft_strdup(game, get_next_line(fd), game->map.map[i]);
		i++;
	}
	game->map.map[game->map.height] = 0;
	close(fd);
}

char	**init_map(t_game *game, char *argv)
{
	int		fd;

	check_name(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	map_height(game, fd);
	map_copy(game, argv);
	check_number_of_elems(game);
	is_closed(game);
	where_p(game);
	is_possible(game);
	return (game->map.map);
}
