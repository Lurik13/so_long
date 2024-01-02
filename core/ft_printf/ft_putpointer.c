/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:19:40 by lribette          #+#    #+#             */
/*   Updated: 2023/11/03 16:02:35 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexaptr(unsigned long long n, char *s)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_puthexaptr(n / 16, s);
		len += ft_puthexaptr(n % 16, s);
	}
	else
		len += ft_putchar(s[n % 16]);
	return (len);
}

int	ft_putpointer(unsigned long long n, char *s)
{
	int	len;

	len = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (n > 0)
		len += ft_putstr("0x");
	len += ft_puthexaptr(n, s);
	return (len);
}
