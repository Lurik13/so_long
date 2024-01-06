/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:17 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 11:23:07 by lribette         ###   ########.fr       */
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
	void	*collec_3;
	void	*collec_b;
	void	*collec_u;
	void	*collec_g;
	void	*collec_d;
	void	*collec_i;
	void	*collec_r;
	void	*collec_5;
	void	*collec_p;
}	t_vars;

typedef struct s_game
{
	t_elements	map;
	t_player	player;
	t_vars		window;
}	t_game;

int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

void	sort_elements(t_game *game, char *str);
void	check_number_of_elems(t_game *game);

void	is_closed(t_game *game);
void	where_p(t_game *game);
void	is_possible(t_game *game);

void	check_name(char *argv);
void	map_height(t_game *game, int fd);

void	display_item(t_game *game, char c, int x, int y);
void	set_xpm(t_game *game);

char	*ft_strdup(t_game *game, char *s, char *str);
void	map_copy(t_game *game, char *argv);
char	**init_map(t_game *game, char *argv);

void	set_window(t_game *game);
void	set_images(t_game *game);
int		ft_destroy_window(t_game *game);

void	ft_error(char *str);
int	free_map(t_game *game);
void	ft_free_error(t_game *game, char *str);

#endif