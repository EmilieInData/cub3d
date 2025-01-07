/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:25:37 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:52:29 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*c;

	total = count * size;
	c = (char *)malloc(total);
	if (c == 0)
		return (0);
	ft_bzero(c, total);
	return (c);
}
/*
int main()
{
	size_t c = 3;
	size_t b = sizeof(int);
	int *arr = (int *)ft_calloc(c,b);
	if (arr == NULL)
	{
		printf("memory allocation failed.");
		return (1);
	}
	printf("memory alloceted successfully");
	free(arr);

	return (0);
}
*/
