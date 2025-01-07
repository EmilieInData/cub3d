/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:28:47 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 11:12:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	int				i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char cr[7] = "hello";
	char ct[7] = "hewlo";
	size_t l = 5 * sizeof(char);

	printf("%d\n",ft_memcmp(cr, ct, l));
	printf("%d\n", memcmp(cr, ct, l));
	return (0);
}
DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical,
     otherwise returns the difference between the first two differing bytes
*/
