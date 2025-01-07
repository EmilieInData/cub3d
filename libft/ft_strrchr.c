/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:02:12 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:47:13 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;
	char	*st;

	i = 0;
	b = (char)c;
	st = (char *)s;
	while (st[i])
		i++;
	while (i >= 0)
	{
		if (st[i] == b)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	const char name[] = "Julia";
	int c = 'l';
	printf ("%s\n", ft_strrchr(name, c));
	printf ("%s\n", strrchr(name, c));
	return (0);
}
The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.
 The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/
