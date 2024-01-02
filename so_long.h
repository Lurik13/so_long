/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/02 22:35:18 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

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
void	map_init(t_elements map, char *argv);

#endif