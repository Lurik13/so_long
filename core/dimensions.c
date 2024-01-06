/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:59:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/06 21:27:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	check_name(char *argv)
{
	int	i;

	i = len(argv) - 3;
	if (argv[i] != 'b' && argv[i + 1] != 'e' && argv[i + 2] != 'r')
		ft_error("Wrong file type");
}

void	map_height(t_game *g, int fd)
{
	char	*result;

	result = get_next_line(fd);
	if (!result || result[0] == '\0')
		ft_error("Empty file");
	g->map.height = 0;
	g->map.length = len(result);
	while (result)
	{
		free(result);
		result = get_next_line(fd);
		if (result && g->map.length != len(result))
		{
			free(result);
			ft_error("Not rectangular");
		}
		g->map.height++;
	}
	close(fd);
}
