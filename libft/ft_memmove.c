/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:03:55 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:29:04 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len -1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char src_1 [3] = "ass";
	char src_2 [3] = "ass";
	size_t length = 6 * sizeof(char);

	printf("%s\n", ft_memmove(src_1 + 1, src_1, length));
	printf("%s\n", memmove(src_2 + 1, src_2, length));
	return (0);
}*/
