/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:33:03 by lribette          #+#    #+#             */
/*   Updated: 2024/01/01 17:52:49 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	int	i;

	i = -1;
	write(1, "Error\n", 6);
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Vous devez inclure un fichier .ber");
	(void)argv;
	//error(argv[1]);
}