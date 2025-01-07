/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:49:40 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/12 13:30:49 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_hex_up(unsigned int nb)
{
	int		i;
	int		b;
	char	str[16];
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb == 0)
		return (write (1, "0", 1));
	while (nb > 0)
	{
		b = nb % 16;
		str[i] = base[b];
		nb = nb / 16;
		i++;
	}
	str[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		if ((write(1, &str[i], 1) == -1))
			return (-1);
		i--;
	}
	return (ft_len(str));
}

int	ft_hex_low(unsigned int nb)
{
	int		i;
	int		b;
	char	str[16];
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb == 0)
		return (write (1, "0", 1));
	while (nb > 0)
	{
		b = nb % 16;
		str[i] = base[b];
		nb = nb / 16;
		i++;
	}
	str[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		if ((write(1, &str[i], 1) == -1))
			return (-1);
		i--;
	}
	return (ft_len(str));
}

int	ft_hex_low2(unsigned long nb)
{
	int		i;
	int		b;
	char	str[120];
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb == 0)
		return (write (1, "0", 1));
	while (nb > 0)
	{
		b = nb % 16;
		str[i] = base[b];
		nb = nb / 16;
		i++;
	}
	str[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		if ((write(1, &str[i], 1) == -1))
			return (-1);
		i--;
	}
	return (ft_len(str));
}

int	punt(unsigned long nb)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	return (ft_hex_low2(nb) + 2);
}
