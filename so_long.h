/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/05 23:24:10 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./mlx_linux/mlx.h"

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*ground;
	void	*wall;
	void	*blocked_exit;
	void	*opened_exit;
	void	*collectible_3;
	void	*collectible_b;
	void	*collectible_d;
	void	*collectible_u;
	void	*collectible_g;
	void	*collectible_i;
	void	*collectible_r;
	void	*collectible_5;
	void	*collectible_p;
}	t_vars;

int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

void	sort_elements(t_elements *map, char *str);
void	check_number_of_elems(t_elements *map);

void	is_closed(t_elements *map);
void	where_p(t_elements *map, t_player *player);
void	is_possible(t_elements *map, t_player *player);

void	check_name(char *argv);
void	map_height(t_elements *map, int fd);

void	display_item(t_vars *window, char c, int x, int y);

char	*ft_strdup(t_elements *map, char *s, char *str);
void	map_copy(t_elements *map, char *argv);
char	**init_map(t_elements *map, t_player *player, char *argv);

void	set_window(t_elements *map, t_player *player, t_vars *window);
void	set_images(t_elements *map, t_player *player, t_vars *window);

void	ft_error(char *str);
int	free_map(t_elements *map);
void	ft_free_error(t_elements *map, char *str);

#endif