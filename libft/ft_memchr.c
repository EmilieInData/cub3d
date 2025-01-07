/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:35:32 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:28:18 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	int				i;

	str = (unsigned char *)s;
	a = (unsigned char) c;
	i = 0;
	while (i < (int)n)
	{
		if (str[i] == a)
			return (&str[i]);
		if (str[i] != a)
			i++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[8] = "hellosd";
	int c = 'l';
	size_t n = 7 * sizeof(char);

	printf("%p\n", ft_memchr(s1, c, n));
	printf("%p\n", memchr(s1, c, n));
	return(0);
}
The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.
The memchr() function returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes.
*/
