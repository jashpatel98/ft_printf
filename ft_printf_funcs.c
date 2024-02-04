/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japatel <japatel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:01:49 by japatel           #+#    #+#             */
/*   Updated: 2023/12/12 17:53:13 by japatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int l)
{
	if ((write(1, &c, 1)) == -1)
		return (-1);
	return (l + 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = b;
	value = (unsigned char)c;
	while (len > 0)
	{
		*ptr = value;
		ptr++;
		len--;
	}
	return (b);
}

int	ft_putnbr(long int n, int l)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (l + 11);
	}
	if (n < 0)
	{
		if ((write(1, "-", 1)) == -1)
			return (-1);
		l++;
		n = -n;
	}
	if (n >= 10)
		l = ft_putnbr(n / 10, l);
	if (l >= 0)
		l = ft_putchar(n % 10 + '0', l);
	return (l);
}

int	ft_putstr(char *s, int l)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		l += 6;
	}
	else
	{
		while (*s != '\0' && l != -1)
		{
			l = ft_putchar(*s, l);
			s++;
		}
	}
	return (l);
}
