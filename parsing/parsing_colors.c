/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/14 14:38:10 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*fc_clean_args(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ",")
	{
		if (str[i] == ' ' || str[i] == '	')
			i++;
		else
			exit(error_msg("colors informations are not appropriate", data), 1);
	}
	if (!str[i])
		exit (error_msg("not enough colors informations", data), 1);
	i++;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (!str[i])
		exit (error_msg("not enough colors informations", data), 1);
	return (&str[i]);
}

char	*fc_check_args(char *str, t_data *data, t_color *fc, int *color)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 0 || i > 3 || (str[i] != "," && str[i] != ' ' && str[i] != '	'))
		exit (error_msg("colors informations are not appropriate", data), 1);
	tmp = malloc (i + 1 * sizeof (char));
	if (!tmp)
		exit (error_msg("malloc didn't work correctly", data), 1);
	ft_strlcpy(tmp, str, i); // A FAIRE: verifier la taille
	data->map->fc->color = atoi(tmp);
	free (tmp);
	if (data->map->fc->color < 0 || data->map->fc->color > 255)
		exit (error_msg("incorrect color number", data), 1);
	return (&str[i]);
}

int	fc_check(char *str, t_data *data, t_color *fc)
{
	int		i;
	char	*tmp;

	if (fc->red != -1) // checker si pas doublons
		exit (error_msg("duplicate colors element", data), 1);
	if (str[1] != ' ' && str[1] != '	')
		exit (error_msg("identifier argument is not appropriate", data), 1);
	while (str[i] && str[i] == ' ' || str[i] == '	')
		i++;
	if (!str[i])
		exit (error_msg("colors informations are missing", data), 1);
	//str = &str[i];
	str = fc_check_args(&str[i], data, fc, fc->red);
	str = fc_clean_args(str, data);
	str = fc_check_args(str, data, fc, fc->green);
	str = fc_clean_args(str, data);
	str = fc_check_args(str, data, fc, fc->blue);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
			i++;
		else
			exit (error_msg("too much colors informations", data), 1);
	}
	return (0);
}
