/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:26:20 by ineimatu          #+#    #+#             */
/*   Updated: 2024/04/24 12:05:45 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	size_t	b;

	i = 0;
	b = ft_strlen(s);
	if (!s)
		return (NULL);
	if (b < start)
		len = 0;
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while ((i < (int)len) && (s[start] != '\0') && (start < ft_strlen(s)))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}
/*
int main(void)
{
	char const s[10] = "156735429";
	printf("%s", ft_substr(s, 4, 3));

	return (0);
}*/
