/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:32:52 by lribette          #+#    #+#             */
/*   Updated: 2024/01/02 19:41:58 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort_elements(char *str, t_list map)
{
	int		len;
	t_list	map;

	len = ft_strlen(str);
	while (--len >= 0)
	{
		if (str[len] == '0')
			map->nb_of_void++;
		if (str[len] == '1')
			map->nb_of_walls++;
		if (str[len] == 'C')
			map->nb_of_collectibles++;
		if (str[len] == 'E')
			map->nb_of_exits;
		if (str[len] == 'P')
			map->nb_of_starts;
	}
}

void	check_rectangular(char *map)
{
	char	*result;
	int		fd;
	int		len;
	t_list	map;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible de lire le fichier .ber");
	}
	result = get_next_line(fd);
	len = ft_strlen(result);
	while (result)
	{
		sort_elements(result);
		//ft_printf("%s\n", result);
		result = get_next_line(fd);
		if (ft_strlen(result) != len)
			ft_error("La map n'est pas rectangulaire");
	}
	free(result);
}

int	map_heigth(t_list map, int fd)
{
	char	*result;

	result = get_next_line(fd);
	map->height = 1;
	while (result)
	{
		result = get_next_line
		map->height++;
	}
}

void	map_init(t_list map, char *argv)
{
	int		fd;
	char	*result;
	
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("Impossible de lire le fichier .ber");
	}
	map_heigth(map, fd);
}
