/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:52 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 16:05:12 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(t_elements *map, char *s, char *str)
{
	int		i;

	i = 0;
	str = malloc((map->length + 1) * sizeof(char));
	if (!str)
		ft_error("Malloc failed");
	while (i < map->length)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

void	map_copy(t_elements *map, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	map->map = malloc((map->height + 1) * sizeof(char *));
	if (!map->map)
		ft_error("Malloc failed");
	i = 0;
	while (i < map->height)
	{
		map->map[i] = ft_strdup(map, get_next_line(fd), map->map[i]);
		i++;
	}
	map->map[map->height] = 0;
	close(fd);
}

char	**init_map(t_elements *map, t_player *player, char *argv)
{
	int		fd;

	check_name(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	map_height(map, fd);
	map_copy(map, argv);
	check_number_of_elems(map);
	is_closed(map);
	where_p(map, player);
	is_possible(map, player);
	return (map->map);
}
