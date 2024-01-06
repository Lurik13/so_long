/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:43:53 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 17:00:22 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_item(t_game *g, char c, int x, int y)
{
	if (c == 'o')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.g, x, y);
	else if (c == '1')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.w, x, y);
	else if (c == 'e')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.b_e, x, y);
	else if (c == '3')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_3, x, y);
	else if (c == 'B')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_b, x, y);
	else if (c == 'D')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_d, x, y);
	else if (c == 'U')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_u, x, y);
	else if (c == 'G')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_g, x, y);
	else if (c == 'I')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_i, x, y);
	else if (c == 'R')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_r, x, y);
	else if (c == '5')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_5, x, y);
	else if (c == 'p')
		mlx_put_image_to_window(g->win.mlx, g->win.win, g->win.c_p, x, y);
}

void	set_xpm(t_game *g)
{
	int	sz;

	sz = 32;
	g->win.g = mlx_xpm_file_to_image(g->win.mlx, "./assets/0.xpm", &sz, &sz);
	g->win.w = mlx_xpm_file_to_image(g->win.mlx, "./assets/1.xpm", &sz, &sz);
	g->win.b_e = mlx_xpm_file_to_image(g->win.mlx, "./assets/e.xpm", &sz, &sz);
	g->win.o_e = mlx_xpm_file_to_image(g->win.mlx, "./assets/E.xpm", &sz, &sz);
	g->win.c_3 = mlx_xpm_file_to_image(g->win.mlx, "./assets/3.xpm", &sz, &sz);
	g->win.c_b = mlx_xpm_file_to_image(g->win.mlx, "./assets/B.xpm", &sz, &sz);
	g->win.c_u = mlx_xpm_file_to_image(g->win.mlx, "./assets/U.xpm", &sz, &sz);
	g->win.c_g = mlx_xpm_file_to_image(g->win.mlx, "./assets/G.xpm", &sz, &sz);
	g->win.c_d = mlx_xpm_file_to_image(g->win.mlx, "./assets/D.xpm", &sz, &sz);
	g->win.c_i = mlx_xpm_file_to_image(g->win.mlx, "./assets/I.xpm", &sz, &sz);
	g->win.c_r = mlx_xpm_file_to_image(g->win.mlx, "./assets/R.xpm", &sz, &sz);
	g->win.c_5 = mlx_xpm_file_to_image(g->win.mlx, "./assets/5.xpm", &sz, &sz);
	g->win.c_p = mlx_xpm_file_to_image(g->win.mlx, "./assets/P.xpm", &sz, &sz);
}

static int	calcul(t_game *g, int y, int x)
{
	int	hei;
	int	len;

	hei = g->map.height;
	len = g->map.length;
	if (x * 2 < len && y * 2 < hei)
		return (((hei * len * 73) / (y * x)) % 8);
	else if (len <= x * 2 && y * 2 < hei)
		return (((hei * len * 127) / (y * (len - x))) % 8);
	else if (x * 2 < len && hei <= y * 2)
		return (((hei * len * 167) / ((hei - y) * x)) % 8);
	else if (len <= x * 2 && hei <= y * 2)
		return (((hei * len * 199) / ((hei - y) * (len - x))) % 8);
	return (0);
}

void	which_collectible(t_game *g)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	str = "3BUGDIR5";
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x])
		{
			if (g->map.map[y][x] == 'c')
			{
				ft_printf("x : %d, y : %d, g->map.height : %d, g->map.length : %d, x * y : %d, g->map.height * g->map.length : %d, result : %d\n", x, y, g->map.height, g->map.length, x * y, g->map.height * g->map.length, ((g->map.height * g->map.length) / (x * y)) % 8);
				g->map.map[y][x] = str[calcul(g, y, x)];
			}
			x++;
		}
		y++;
	}
}
