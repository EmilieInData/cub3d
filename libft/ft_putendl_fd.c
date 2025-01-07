/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:13:43 by ineimatu          #+#    #+#             */
/*   Updated: 2024/02/01 16:39:54 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	n;

	n = 0;
	if (s)
	{
		while (s[n] != '\0')
			write (fd, &s[n++], 1);
	}
	write (fd, "\n", 1);
}
/*
int main()
{
	char s[] = "sipseot";
	ft_putendl_fd(s, 1);
	return (0);
}
*/
