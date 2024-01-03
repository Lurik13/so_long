/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:52 by lribette          #+#    #+#             */
/*   Updated: 2024/01/03 23:25:30 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	so_long_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	map_height(t_elements map, int fd)
{
	char	*result;
	int		len;

	result = get_next_line(fd);
	map.height = 0;
	len = so_long_strlen(result);
	while (result)
	{
		free(result);
		result = get_next_line(fd);
		if (result && len != so_long_strlen(result))
			ft_error("La map n'est pas rectangulaire");
		map.height++;
	}
	close(fd);
	return (map.height);
}

char	*ft_strdup(char *s, char *map)
{
	int		i;
	int		len;

	i = 0;
	len = so_long_strlen(s);
	map = malloc((len + 1) * sizeof(char));
	if (!map)
		ft_error("Probleme de malloc");
	while (i < len)
	{
		map[i] = s[i];
		i++;
	}
	map[i] = '\0';
	free(s);
	return (map);
}

void	map_copy(t_elements map, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible de lire le fichier .ber");
	}
	i = 0;
	while (i < map.height)
	{
		map.map[i] = ft_strdup(get_next_line(fd), map.map[i]);
		i++;
	}
	map.map[map.height] = 0;
	close(fd);
}

void	sort_elements(t_elements map)
{
	int		len;

	len = so_long_strlen(str);
	while (--len >= 0)
	{
		if (map.map[len] == '0')
			map.nb_of_void++;
		if (map.map[len] == '1')
			map.nb_of_walls++;
		if (map.map[len] == 'C')
			map.nb_of_collectibles++;
		if (map.map[len] == 'E')
			map.nb_of_exits;
		if (map.map[len] == 'P')
			map.nb_of_starts;
		if (map.map[len] == '\n')
			continue ;
		else
			ft_error("Certains symboles ne figurent pas dans notre liste d'elements");
	}
} //a faire pour chaque ligne !

void	check_number_of_elems(t_elements map)
{
	map.nb_of_void = 0;
	map.nb_of_walls = 0;
	map.nb_of_collectibles = 0;
	map.nb_of_exits = 0;
	map.nb_of_starts = 0;
	sort_elements(map);
	if (nb_of_collectibles < 1 || nb_of_exits != 1 || nb_of_starts != 1)
		free_map(map);
	if (nb_of_collectibles < 1)
		ft_error("Il faut au moins 1 collectible");
	if (nb_of_exits != 1)
		ft_error("Il faut une sortie");
	if (nb_of_starts != 1)
		ft_error("Il faut une position de depart");
}

char	**map_init(t_elements map, char *argv)
{
	int		fd;
	
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible de lire le fichier .ber");
	}
	map.height = map_height(map, fd);
	map.map = malloc((map.height + 1) * sizeof(char *));
	if (!map.map)
		ft_error("Probleme de malloc");
	map_copy(map, argv);
	int	i = 0;
	while (map.map[i])
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	//check_number
	//check fermee
	//check possible
	return (map.map);
}
