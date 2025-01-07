/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:42 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/12 13:31:59 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = ft_putchar(va_arg(args, int));
	if (s == '%')
		count = ft_putchar('%');
	if (s == 's')
		count = ft_putstr(va_arg(args, char *));
	if ((s == 'd') || (s == 'i'))
		count = ft_putnbr(va_arg(args, int));
	if (s == 'u')
		count = ft_num(va_arg(args, int));
	if (s == 'x')
		count = ft_hex_low(va_arg(args, unsigned int));
	if (s == 'X')
		count = ft_hex_up(va_arg(args, unsigned int));
	if (s == 'p')
		count = punt(va_arg(args, unsigned long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		b;
	va_list	argt;

	va_start(argt, str);
	i = 0;
	b = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] != '\0')
				b += ft_check(argt, str[i]);
		}
		else
			b += ft_putchar(str[i]);
		i++;
		if (b == -1)
			return (-1);
	}
	va_end(argt);
	return (b);
}
