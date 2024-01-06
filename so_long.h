/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 16:30:02 by lribette         ###   ########.fr       */
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
	int	count;
}	t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*g;
	void	*w;
	void	*b_e;
	void	*o_e;
	void	*c_3;
	void	*c_b;
	void	*c_u;
	void	*c_g;
	void	*c_d;
	void	*c_i;
	void	*c_r;
	void	*c_5;
	void	*c_p;
}	t_vars;

typedef struct s_game
{
	t_elements	map;
	t_player	player;
	t_vars		win;
}	t_game;

int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

void	sort_elements(t_game *g, char *str);
void	check_number_of_elems(t_game *g);

void	is_closed(t_game *g);
void	where_p(t_game *g);
void	is_possible(t_game *g);

void	check_name(char *argv);
void	map_height(t_game *g, int fd);

void	display_item(t_game *g, char c, int x, int y);
void	set_xpm(t_game *g);
void	which_collectible(t_game *g);

char	*ft_strdup(t_game *g, char *s, char *str);
void	map_copy(t_game *g, char *argv);
char	**init_map(t_game *g, char *argv);

void	set_window(t_game *g);
void	set_images(t_game *g);
int		ft_check_key(int keycode, t_game *g);
int		ft_destroy_window(t_game *g);

void	ft_error(char *str);
int		free_map(t_game *g);
void	ft_free_error(t_game *g, char *str);

#endif