/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:43:53 by lribette          #+#    #+#             */
/*   Updated: 2024/01/05 19:17:52 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_item(t_vars *window, char c, int x, int y)
{
	int		size;
	void	*img;
	char	*xpm;

	if (c == 'o')
		xpm = "./assets/Ground.xpm";
	else if (c == '1')
		xpm = "./assets/Wall.xpm";
	else if (c == 'c' || c == 'e') //ici 'e'
		xpm = "./assets/IG-88.xpm";
	else if (c == '3')
		xpm = "./assets/11-3K.xpm";
	else if (c == 'B')
		xpm = "./assets/B1.xpm";
	else if (c == 'D')
		xpm = "./assets/Droideka.xpm";
	else if (c == 'U')
		xpm = "./assets/DUM.xpm";
	else if (c == 'G')
		xpm = "./assets/GNK.xpm";
	else if (c == 'I')
		xpm = "./assets/IG-88.xpm";
	else if (c == 'R')
		xpm = "./assets/R2-D2.xpm";
	else if (c == '5')
		xpm = "./assets/R5-D4.xpm";
	else if (c == 'p')
		xpm = "./assets/Jawa.xpm";
	if (!c)
		xpm = NULL;
	else
	{
		img = mlx_xpm_file_to_image(window->mlx, xpm, &size, &size);
		mlx_put_image_to_window(window->mlx, window->win, img, x * 32, y * 32);
	}
}
