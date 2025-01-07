/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:35:54 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 16:41:07 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int		i;
	long	lgn;

	lgn = n;
	if (lgn == 0)
		return (2);
	i = 1;
	if (lgn < 0)
	{
		i++;
		lgn = lgn * -1;
	}
	while (lgn != 0)
	{
		lgn = (lgn / 10);
		i++;
	}
	return (i);
}

char	*ft_change(int n, char *c)
{
	int		i;
	long	lgn;

	lgn = n;
	i = ft_len(n);
	c[i - 1] = '\0';
	if (lgn < 0)
	{
		c[0] = '-';
		lgn = lgn * -1;
	}
	while (lgn > 0)
	{
		c[i - 2] = (lgn % 10) + '0';
		lgn = lgn / 10;
		i--;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	lgn;

	lgn = n;
	len = ft_len(n);
	str = malloc((len) * sizeof(char));
	if (!str)
		return (NULL);
	if (lgn == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = ft_change(n, str);
	return (str);
}
