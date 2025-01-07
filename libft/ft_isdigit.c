/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:00:52 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 10:22:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}
/*
int main()
{
	int a = 50;
	printf("%d", ft_isdigit(a));
	printf("%d", isdigit(a))
	return (0);
}
The isdigit() function tests for a decimal digit character
*/
