/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 16:07:28 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_elements
{
	int		length;
	int		height;
	int		nb_of_void;
	int		nb_of_walls;
	int		nb_of_collectibles;
	int		nb_of_exits;
	int		nb_of_starts;
	char	**map;
}	t_elements;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

void	sort_elements(t_elements *map, char *str);
void	check_number_of_elems(t_elements *map);

void	is_closed(t_elements *map);
void	where_p(t_elements *map, t_player *player);
void	is_possible(t_elements *map, t_player *player);

void	check_name(char *argv);
void	map_height(t_elements *map, int fd);

char	*ft_strdup(t_elements *map, char *s, char *str);
void	map_copy(t_elements *map, char *argv);
char	**init_map(t_elements *map, t_player *player, char *argv);

void	ft_error(char *str);
void	free_map(t_elements *map);
void	ft_free_error(t_elements *map, char *str);

#endif