/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_OLD.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/14 14:33:08 by esellier         ###   ########.fr       */
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
