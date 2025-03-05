/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:40:27 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 12:11:18 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	double_to_int(int door, double player)
{
	int	tmp;

	tmp = 0;
	if (player > door)
		tmp = floor (player);
	if (player < door)
		tmp = ceil (player);
	return (tmp);
}

int	check_length(char **matrix, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[j])
		j++;
	if (y < j)
	{
		while (matrix[y][i])
			i++;
		return (i);
	}
	return (-1);
}
