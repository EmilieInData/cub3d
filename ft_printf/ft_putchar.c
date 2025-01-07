/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:40:38 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/12 13:33:52 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}
/*
int main()
{
	char c = 's';
	char c1 = '5';
	int i = ft_putchar(c);
	int b = ft_putchar(c1);
	printf("%u\n", i);
	printf("%u\n", b);
	return (0);
}*/
