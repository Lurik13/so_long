/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/03 23:14:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
//# include "core/libft/libft.h"

typedef struct      s_elements
{
	int		length;
	int		height;
	int		nb_of_void;
	int		nb_of_walls;
	int		nb_of_collectibles;
	int		nb_of_exits;
	int		nb_of_starts;
	char	**map;
}                   t_elements;

int	ft_printf(const char *format, ...);
char	*get_next_line(int fd);
void	ft_error(char *str);
int	map_height(t_elements map, int fd);
char	*ft_strdup(char *s, char *map);
void	map_copy(t_elements map, char *argv);
void	sort_elements(t_elements map);
char	**map_init(t_elements map, char *argv);
void	free_map(t_elements map);

#endif