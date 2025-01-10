/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/10 19:33:05 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*map_check(char *str, t_data *data)
{
	
}

char	**fc_check(char *str, t_data *data)
{
	
}

int	news_check(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] == 'N' || str[i] == 'S') //check si c'est lisible de mettre tous les args ensembles
	{
		if (str[i + 1] && str[i + 1] == 'O' && str[i + 2] && str[i + 2] == ' ')
			//fonction qui virent les espaces et checkent l'arg et le met dans la struct
	}
	else if (str[i] == 'W')
	{
		if (str[i + 1] && str[i + 1] == 'E' && str[i + 2] && str[i + 2] == ' ')
			//fonction qui virent les espaces et checkent l'arg et le met dans la struct
	}
	else if (str[i] == 'E')
	{
		if (str[i + 1] && str[i + 1] == 'A' && str[i + 2] && str[i + 2] == ' ')
			//fonction qui virent les espaces et checkent l'arg et le met dans la struct
	}
	else
		exit (error_msg("scene elements are not appropriate", data), 1);
	return (0);
}

void	*clean_line(char *str, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		return (NULL); // ou array de un NULL
	if (str[i] == '1' || str[i] == '0')
		return (map_check(str, data)); //checker juste si c'est des 0 ou 1 et le player et renvoyer une ligne
	str = &str[i]; //virer ce qu'il y a avant les characteres seulement si pas la map
	if (str[i] == 'F' || str[i] == 'C')
		return (fc_check(str, data));
	if (str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
		return (news_check(str, data));
	else
		exit (error_msg("scene elements are not appropriate", data), 1);
}


//mettre les args dans un array (en limitant le nombre a 1 de plus que necessaire pour checker le nb d'args)
//checker les arguments, le nombre, et les choses autorisees ou non
	// si F ou C faire un atoi pour checker les numeros
	//si NO ... checker si le fichier est ok
//la map en dernier, chaque ligne doit commencer et finir par un 1 (avec des espaces avant ou non)