/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:59:24 by lribette          #+#    #+#             */
/*   Updated: 2024/01/04 12:55:39 by lribette         ###   ########.fr       */
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

void	map_height(t_elements *map, int fd)
{
	char	*result;

	result = get_next_line(fd);
	map->height = 0;
	map->length = len(result);
	while (result)
	{
		free(result);
		result = get_next_line(fd);
		if (result && map->length != len(result))
		{
			free(result);
			ft_error("Not rectangular");
		}
		map->height++;
	}
	close(fd);
}
