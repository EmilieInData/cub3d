/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:02:28 by ineimatu          #+#    #+#             */
/*   Updated: 2024/04/24 12:02:22 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
     strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
	 DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).
	 strlcpy() and strlcat() take the full size of the destination buffer and
     guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).
	 */
#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		if (dstsize < srcsize)
			dst[dstsize - 1] = '\0';
		else if (dstsize != 0)
			dst[i] = '\0';
	}
	return (srcsize);
}
/*
int main ()
{
	char dst[] = "Abracadabra";
	char src[] = "hop";
	size_t i = 7;
	printf("%zu\n", ft_strlcpy(dst, src, i));
	printf("%zu\n", strlcpy(dst, src, i));
	return (0);
}
*/
