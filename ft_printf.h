/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japatel <japatel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:02:26 by japatel           #+#    #+#             */
/*   Updated: 2023/12/12 17:46:49 by japatel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c, int l);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putnbr(long int n, int l);
int		ft_putstr(char *s, int l);
int		ft_printf(const char *args, ...);

#endif