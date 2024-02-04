/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japatel <japatel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:02:10 by japatel           #+#    #+#             */
/*   Updated: 2023/12/12 18:31:31 by japatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(unsigned long int n, char c, int l)
{
	long	i;
	long	tmp;
	char	var[16];

	i = 0;
	ft_memset(var, '\0', 16);
	if (n == 0)
		return (ft_putchar('0', l));
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
		{
			var[i++] = tmp + '0';
		}
		else
		{
			var[i++] = (tmp - 10) + c;
		}
		n /= 16;
	}
	tmp = i;
	while (i--)
		ft_putchar(var[i], l);
	return (l + tmp);
}

static int	ft_return_value(char c, va_list vars, int l)
{
	if (c == 'c')
		return (ft_putchar(va_arg(vars, int), l));
	else if (c == 's')
		return (ft_putstr(va_arg(vars, char *), l));
	else if (c == 'p')
		return (-l + ft_putstr("0x", l)
			+ ft_hexa((unsigned long int)va_arg(vars, void *), 'a', l));
	else if (c == 'x')
		return (ft_hexa(va_arg(vars, unsigned int), 'a', l));
	else if (c == 'X')
		return (ft_hexa(va_arg(vars, unsigned int), 'A', l));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(vars, int), l));
	else if (c == 'u')
		return (ft_putnbr(va_arg(vars, unsigned int), l));
	else
		return (ft_putchar(c, l));
}

int	ft_printf(const char *argus, ...)
{
	va_list	vars;
	int		l;

	l = 0;
	va_start(vars, argus);
	while (*argus)
	{
		if (*argus == '%')
		{
			l = ft_return_value(*(++argus), vars, l);
		}
		else
			l = ft_putchar(*argus, l);
		argus++;
	}
	va_end(vars);
	return (l);
}
