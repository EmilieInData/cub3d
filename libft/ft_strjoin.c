/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:17:15 by ineimatu          #+#    #+#             */
/*   Updated: 2024/04/23 14:12:54 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		b;
	int		c;
	char	*str;

	i = 0;
	c = 0;
	b = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((!s1) || (!s2) || (!str))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[c++] = s1[i];
		i++;
	}
	while (s2[b])
	{
		str[c] = s2[b];
		b++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
/*
int main(void)
{
	char str[13] = "dkjfpeog";
	char str2[10] = "gojos";
	printf("%s", ft_strjoin(str,str2));
	return (0);
}*/
