/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:56:41 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 10:12:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	else
		return (0);
}
/*
int main()
{
	int a = 100;
	printf("%d/n", ft_isalpha(a));
	printf("%d/n", isalpha(a));
	return (0);
}
The isalpha() function tests for any character for which isupper(3) or
     islower(3) is true.  The value of the argument must be representable as
     an unsigned char or the value of EOF.
*/
