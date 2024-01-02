/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:05:47 by lribette          #+#    #+#             */
/*   Updated: 2023/11/03 16:05:53 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char c)
{
	int		len;
	char	*low;

	len = 0;
	low = "0123456789abcdef";
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putpointer(va_arg(args, unsigned long long), low);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_puthexa(va_arg(args, unsigned int), low);
	else if (c == 'X')
		len += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
	}
	return (len);
}

/*
int	main(void)
{
	ft_printf("ft_printf : %p %p \n", 0, 0);
	//printf("   printf : %p %p", 0, 0);
}*/
