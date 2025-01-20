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

#include "includes/cub3d.h"

int find_distance_v(t_player player, int x, int y)
{
	int dist;

	if (player.angle >= 270 && player.agle <= 90)
		x = player.player_x - x;
	else
		x = x - player.player_x;
	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;
	return (dist)
}

int find_distance_h(int x, int y)
{
	int dist;

	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;
	return(dist)
}
