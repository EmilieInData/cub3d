/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:20 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 10:19:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int main()
{
	int c = 130;
	int b = 5;
	printf("%d", ft_isascii(b));
	printf("%d", isascii(b))
	return (0);
}
 The isascii() function tests for an ASCII character, which is any
     character between 0 and octal 0177 inclusive.
*/
