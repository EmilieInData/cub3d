/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/13 20:06:17 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	fc_color_struc(t_data *data, t_color *fc, int *color, char *tmp)
{
	data->map->fc->color = atoi(tmp);
	free (tmp);
	if (data->map->fc->color < 0 || data->map->fc->color > 255)
		exit (error_msg("incorrect color number", data), 1);
}

char	*fc_quite_space(char *str, t_data *data, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && tmp[j])
	{
		if (str[i] != ' ' && str[i] != '	')
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
		else
			i++;
	}
	tmp[j] == '\0';
	return (tmp);
}

char	*fc_clean_line(char *str, t_data *data)
{
	int		i;
	int		space;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] == ' ' || str[i] == '	')
		i++;
	if (!str[i])
		exit (error_msg("colors informations are missing", data), 1);
	str = &str[i];
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
			space++;
		i++;
	}
	if (space == 0)
		return (str);
	tmp = malloc (i + 1 * sizeof (char));
	if (!tmp)
		exit (error_msg("malloc didn't work correctly", data), 1);
	return (fc_quite_space(str, data, tmp));
}

void	fc_control_args(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9') //compter le nombre de caractere pour reserver l'espace
		i++;
	if (i == 0 || i > 3)
		exit (error_msg("colors informations are not appropriate", data), 1);
	tmp = malloc (i + 1 * sizeof (char));
	if (!tmp)
		exit (error_msg("malloc didn't work correctly", data), 1);
	ft_strlcpy(tmp, str, i); // A FAIRE: verifier la taille
	}

char	**fc_check(char *str, t_data *data, t_color *fc)
{
	int		i;
	char	*tmp;

	if (fc->red != -1) // checker si pas doublons
		exit (error_msg("duplicate colors element", data), 1);
	if (str[1] != ' ' && str[1] != '	')
		exit (error_msg("identifier argument is not appropriate", data), 1);
	str = fc_clean_line(&str[1], data);

	fc_control_args(str, data);
	fc_color_struc(data, fc, fc->red, tmp);

	if (!str[i])
		exit (error_msg("not enough colors informations", data), 1);
	if (str[i] != ",")
		exit (error_msg("colors informations are not appropriate", data), 1);
	str = &str[i + 1];

	fc_control_args(str, data);
	fc_color_struc(data, fc, fc->green, tmp);

	if (!str[i])
		exit (error_msg("not enough colors informations", data), 1);
	if (str[i] != ",")
		exit (error_msg("colors informations are not appropriate", data), 1);
	str = &str[i + 1];

	fc_control_args(str, data);
	fc_color_struc(data, fc, fc->blue, tmp);
	if (str[i])
		exit (error_msg("too much colors informations", data), 1);
}
//A FAIRE = attention seulement un "," accepte

char	*news_args_check(char *str, t_data *data, char *news)
{
	int		i;
	char	*tmp;

	i = 0;
	if (news) // checker si pas doublons
		exit (error_msg("duplicate texture element ", data), 1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ' || str[i] == '	') // enlever les espaces avant l'arg
			i++;
		if (!str[i])
			exit (error_msg("texture path is missing", data), 1);
		str = &str[i]; //mettre le pointeur sur le premier caractere
		i = 0;
		while (str[i] && str[i] != ' ' && str[i] != '	') //compter le nombre de caractere pour reserver l'espace
			i++;
		if (str[i])//checker si plusieurs arg ou finit par autre chose qu'un caractere(pas ok espace apres)
			exit (error_msg("texture argument is not appropriate", data), 1);
		tmp = malloc(i + 1 * sizeof(char));
		if (!tmp)
			exit (error_msg("malloc didn't work correctly", data), 1);
		ft_strlcpy(tmp, str, i); // A FAIRE: verifier la taille
		//checker si le chemin d'acces est ok? ici ou plus tard?
	}
	news = tmp; // A FAIRE = checker si change bien la structure
}

int	news_check(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] && str[i + 1] == 'O' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->no), 0);
	else if (str[i] == 'S' && str[i + 1] && str[i + 1] == 'O' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->so), 0);
	else if (str[i] == 'W' && str[i + 1] && str[i + 1] == 'E' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->we), 0);
	else if (str[i] == 'E' && str[i + 1] && str[i + 1] == 'A' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->ea), 0);
	exit (error_msg("identifier argument is not appropriate", data), 1);
}

void	*check_line(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		return ;
	if (str[i] == '1' || str[i] == '0')
		return (map_check(str, data)); //checker juste si c'est des 0 ou 1 et le player et renvoyer une ligne
	str = &str[i]; //virer ce qu'il y a avant les characteres seulement si pas la map, checker pour le mec dans l'arg de la fonction
	if (str[i] == 'F' || str[i] == 'C')
		return (fc_check(str, data));
	if (str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
		return (news_check(str, data));
	else
		exit (error_msg("scene element is not appropriate", data), 1);
}

//checker les arguments, le nombre, et les choses autorisees ou non
//avant la carte je dois checker avoir bien toutes le sinfos fc et news avant de la creer

//ATTENTION PAS OK LA FONCTION QUI ENLEVE DES SPACES (224 0909 090 , 987, 98)
//JE DOIS VERIFIER QU'IL Y A UNE VIRGULE AVANT OU APRES ENFIN PAS DES CHIFFRES