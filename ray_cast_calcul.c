/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:45:15 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:06:13 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int find_distance_v(t_player player, int x, int y)
{
	int dist;

	if ((player.angle >= 270 && player.angle <= 360) || (player.angle > 0 && player.angle <= 90))
		x = player.position_x - x;
	else
		x = x - player.position_x;
	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;
	printf("%i\n", dist);
	return (dist);
}

int find_distance_h(int x, int y)
{
	int dist;

	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;

	return(dist);
}
