/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:45:07 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 10:15:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int b)
{
	if ((ft_isalpha(b)) || (ft_isdigit(b)))
		return (1);
	else
		return (0);
}
/*
int main()
{
	int b = 100;
	printf("%d", ft_isalnum(b));
	printf("%d", isalnum(b));
	return (0);
}
 The isalnum() function tests for any character for which isalpha(3) or
     isdigit(3) is true.
*/
