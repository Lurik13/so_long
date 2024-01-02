/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:04 by lribette          #+#    #+#             */
/*   Updated: 2023/11/03 14:53:28 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthexa(unsigned int n, char *s);
int	ft_putpointer(unsigned long long n, char *s);

#endif
