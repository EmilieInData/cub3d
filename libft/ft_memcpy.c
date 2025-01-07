/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:04:45 by ineimatu          #+#    #+#             */
/*   Updated: 2024/05/29 14:51:27 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char		*x;
	const char	*y;
	size_t		i;

	i = 0;
	x = dst;
	y = src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
/*
int main(void)
{
	char dst[] = "hello world";
	char src[] = "havo";
	size_t n = 4 * sizeof(char);
	printf("%s", ft_memcpy(dst, src, n));
}
*/
