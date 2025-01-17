/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:35:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/17 17:02:01 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		size;

	size = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (0);
	while (s1[size])
	{
		ptr[size] = s1[size];
		size++;
	}
	ptr[size] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
	const char s1[] = "hola caracola";
	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	return (0);
}
The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.
*/
