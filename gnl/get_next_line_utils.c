/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:07:07 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/06 11:14:20 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

size_t	ft_strln(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_empty_file(char *buff)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strln(buff);
	if (!buff || len <= 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = buff[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return (ft_empty_file(s2));
	res = (char *)malloc(sizeof(char) * ft_strln(s1) + ft_strln(s2) + 1);
	if (!res)
		return (ft_free(s1, 0));
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
