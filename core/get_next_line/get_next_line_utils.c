/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:06:40 by lribette          #+#    #+#             */
/*   Updated: 2023/11/19 18:53:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *result, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = -1;
	str = ft_calloc(ft_strlen(result) + ft_strlen(buffer) + 1, 1);
	if (!str)
		return (NULL);
	while (result && result[i])
	{
		str[i] = result[i];
		i++;
	}
	while (buffer[++j])
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	free(result);
	return (str);
}

char	*ft_calloc(int nbelem, int size)
{
	char	*str;
	int		i;

	str = malloc(nbelem * size);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < nbelem * size)
		str[i] = '\0';
	return (str);
}

int	ft_strchr(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	return (-1);
}
