/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:35:07 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:52:04 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;
	size_t			l;

	zero = (unsigned char *)s;
	l = 0;
	while (l < n)
	{
		zero[l] = 0;
		l++;
	}
}
/*
int	main(void)
{
	char str[] = "jshgljg;k ,lsm'fke";

	ft_bzero(str, 5);
	printf("Final result: %s\n", str);
	return (0);
}
The bzero() function writes n zeroed bytes to the string s.
*/
