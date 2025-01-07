/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:50 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/12 13:34:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_putchar(int c);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_num(unsigned int n);
int	ft_hex_low(unsigned int nb);
int	ft_hex_up(unsigned int nb);
int	punt(unsigned long nb);

#endif
