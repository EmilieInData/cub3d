/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:08:22 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:46 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (dst[i] != '\0')
		i++;
	if (dstsize >= i && dstsize != 0)
	{
		while ((src[b] != '\0') && (i + b < dstsize - 1))
		{
			dst[i + b] = src[b];
			b++;
		}
		dst[i + b] = '\0';
	}
	while (src[b] != '\0')
		b++;
	return (i + b);
}
/*
int main()
{
	char dest[100] = "leo";
	char dest_test[100] = "leo";
	printf("%zu\n", strlcat(dest, "Julia", 0));
	printf("%s\n", dest);
    printf("%zu\n", ft_strlcat(dest_test, "Julia", 0));
	printf("%s\n", dest_test);
	return (0);
}
*/
