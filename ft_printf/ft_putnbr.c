/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:07:20 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/12 13:37:56 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(int nb)
{
	int			i;
	long long	b;

	i = 0;
	b = nb;
	while (b < 0)
	{
		i++;
		b = -nb;
	}
	while (b / 10 != 0)
	{
		i++;
		b /= 10;
	}
	i++;
	return (i);
}

int	ft_putnbr_max(int nb)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr(int n)
{
	int	i;

	i = n;
	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
		return (ft_putnbr_max(n));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		if (ft_putchar(n + 48) == -1)
			return (-1);
	}
	return (count(i));
}

int	len_of_num(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_num(unsigned int n)
{
	char			c;
	int				len;
	unsigned int	temp;

	if (n == 0)
		return (write(1, "0", 1));
	temp = n;
	len = len_of_num(temp);
	if (n > 9)
	{
		if (ft_num(n / 10) == -1)
			return (-1);
		if (ft_num(n % 10) == -1)
			return (-1);
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (len);
}
/*
int main()
{
	int n = 12345;
	printf("%d", n);
	int b = printf("%d\n", n);
	printf("%d", b);
	return (0);i
}
*/
