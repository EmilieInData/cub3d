/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:58:03 by ineimatu          #+#    #+#             */
/*   Updated: 2024/04/23 14:12:24 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	b;
	char	*st;

	i = 0;
	b = (char)c;
	st = (char *)s;
	while (st[i])
	{
		if (st[i] == b)
			return ((char *) &s[i]);
		i++;
	}
	if ((st[i] == '\0') && (b == '\0'))
		return ((char *) &s[i]);
	return (NULL);
}
/*
int main()
{
	const char name[] = "Julia";
	int c = 'l';
	printf ("%s\n", ft_strchr(name, c));
	printf ("%s\n", strchr(name, c));
	return (0);
}
The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is ‘\0’, the
     functions locate the terminating ‘\0’.
The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/
