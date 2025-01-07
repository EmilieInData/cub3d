/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:17:33 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:46:27 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(const char *str, char c)
{
	int	flag;
	int	w;

	flag = 0;
	w = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			w++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (w);
}

char	**ft_memall(char **array, char const *s, char c)
{
	int	i;
	int	w;
	int	a;

	i = 0;
	w = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			w++;
		if ((s[i] == c && w > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			array[a] = malloc(sizeof(char) * (w + 1));
			if (!array[a])
				return (NULL);
			a++;
			w = 0;
		}
		i++;
	}
	return (array);
}

char	**ft_copy(char **array, char const *s, char c)
{
	int	a;
	int	b;
	int	i;

	a = 0;
	b = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			array[a][b++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			array[a][b] = '\0';
		else if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			array[a][b] = '\0';
			a++;
			b = 0;
		}
		i++;
	}
	return (array);
}

char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
	{
		array = malloc(sizeof(char) * 1);
		if (!array)
			return (NULL);
		*array = NULL;
		return (array);
	}
	count = wordcount(s, c);
	array = malloc((count + 1) * sizeof(*array));
	if (!array)
		return (NULL);
	if (ft_memall(array, s, c))
	{
		ft_copy(array, s, c);
		array[count] = NULL;
	}
	else
		array = ft_free(array);
	return (array);
}

/*
 int main(void)
{
	char const s[300] = "this  is supposed  to be words   ";
	char c = ' ';
	int	i;
	char **result;

	i = 0;
	result = ft_split(s, c);
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	ft_free(result);
	return (0);
}
*/
