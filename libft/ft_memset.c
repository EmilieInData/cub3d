/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:31:28 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 15:29:22 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	x;
	unsigned char	*tmp;
	size_t			i;

	x = c;
	tmp = b;
	i = 0;
	while (i < len)
	{
		tmp[i] = x;
		i++;
	}
	return (tmp);
}
/*
int main()
{
	int c = 'b';
	void *a[100] = "ajsfojvoeöwofj";
	printf("%s/n", ft_memset(a, c, 3));
	printf("%s/n", memset(a, c, 3));
}
DESCRIPTION
     The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.

RETURN VALUES
     The memset() function returns its first argument.
*/
