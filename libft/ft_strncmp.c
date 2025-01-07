/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:50 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:51 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*so;
	unsigned char	*st;

	i = 0;
	so = (unsigned char *)s1;
	st = (unsigned char *)s2;
	if (n > 0)
	{
		while ((so[i] == st[i]) && (i < n - 1) && (so[i]) && (st[i]))
		{
			i++;
		}
		return (so[i] - st[i]);
	}
	return (0);
}
/*
int main()
{
	char s1[] = "allar";
	char s2[] = "alla";
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d\n", strncmp(s1, s2, 5));
	return (0);
}
The strcmp() and strncmp() functions lexicographically compare the null-
     terminated strings s1 and s2.

     The strncmp() function compares not more than n characters.  Because
     strncmp() is designed for comparing strings rather than binary data,
     characters that appear after a ‘\0’ character are not compared.
The strcmp() and strncmp() functions return an integer greater than,
     equal to, or less than 0, according as the string s1 is greater than,
     equal to, or less than the string s2. 
*/
