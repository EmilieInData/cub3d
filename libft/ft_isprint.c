/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:44:24 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 10:24:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int d)
{
	if (d >= 32 && d <= 126)
		return (1);
	else
		return (0);
}
/*
int main()
{
	int c = 120;
	int b = 20;
	printf("%d", ft_isprint(b));
	printf("%d", isprint(b))
	return (0);
}
 The isprint() function tests for any printing character, including space
     (‘ ’). #including <ctipe.h>
*/
