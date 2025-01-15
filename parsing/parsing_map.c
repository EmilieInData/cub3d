/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/15 15:33:39 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*map_check(t_data *data, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	
	//toujours un 1 en premier et en dernier (pas de 0)
	//premiere et derniere ligne que de 1 et espaces
	//tab autorises?
	//le player doit etre la qu'une fois
	//checker que murs sont bien fermes par leur position dans l'array
	//floodfill pour checker que sa position est ok ? est-ce necessaire?
	//checker que le dernier arg est bien le bas de la map et pas des args lambdas ajoutes en dessous ou des espaces ou des null,
}

//checker les arguments, le nombre, et les choses autorisees ou non
//le p[ayer ne doit pas etre sur le mur, donc sur les contours
