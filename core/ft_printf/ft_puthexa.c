/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:53:35 by lribette          #+#    #+#             */
/*   Updated: 2023/11/03 14:17:15 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char *s)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_puthexa(n / 16, s);
		len += ft_puthexa(n % 16, s);
	}
	else
		len += ft_putchar(s[n % 16]);
	return (len);
}
