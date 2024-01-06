/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:52 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 18:20:47 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(t_game *g, char *s, char *str)
{
	int		i;

	i = 0;
	str = malloc((g->map.length + 1) * sizeof(char));
	if (!str)
		ft_error("Malloc failed");
	while (i < g->map.length)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

void	map_copy(t_game *g, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	g->map.map = malloc((g->map.height + 1) * sizeof(char *));
	if (!g->map.map)
		ft_error("Malloc failed");
	i = 0;
	while (i < g->map.height)
	{
		g->map.map[i] = ft_strdup(g, get_next_line(fd), g->map.map[i]);
		i++;
	}
	g->map.map[g->map.height] = 0;
	close(fd);
}

char	**init_map(t_game *g, char *argv)
{
	int		fd;

	check_name(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible to read the .ber file");
	}
	map_height(g, fd);
	map_copy(g, argv);
	check_number_of_elems(g);
	is_closed(g);
	where_p(g);
	is_possible(g);
	g->map.is_exit_opened = 0;
	return (g->map.map);
}
