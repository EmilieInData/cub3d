/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/17 19:22:00 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*map_check(t_data *data, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(matrix[0][i] && (matrix[0][i] == ' ' || matrix[0][i] == '	'))
		j++;
	while (matrix[0][1])
	{
		if (matrix[0][i] == 'N' || matrix[0][i] == 'E'
			|| matrix[0][i] == 'W' || matrix[0][i] == 'S')
			exit (error_msg("player can't be in the border", data));
		if (matrix[0][i] != 1 && matrix[0][i] == ' ' )
			exit (error_msg("map border is uncorrect", data));
	}

	//boucle // avec le player position a garder ds la struct//checker si il n'est pas deja la avant
	//derniere ligne
}
	//toujours un 1 en premier et en dernier (pas de 0)
	//premiere et derniere ligne que de 1 et espaces
	//tab autorises?
	//le player doit etre la qu'une fois
	//checker que le dernier arg est bien le bas de la map et pas des args lambdas ajoutes en dessous ou des espaces ou des null,

	//checker que murs sont bien fermes par leur position dans l'array
	//floodfill pour checker la position du player? pas enferme quelque part

//checker les arguments, le nombre, et les choses autorisees ou non
//le p[ayer ne doit pas etre sur le mur, donc sur les contours
