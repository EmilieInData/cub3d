/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 14:34:25 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*fc_clean_args(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] == ' ' || str[i] == '	')
			i++;
		else
			exit(error_msg("colors informations are not appropriate", data));
	}
	if (!str[i])
		exit (error_msg("not enough colors informations", data));
	i++;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (!str[i])
		exit (error_msg("not enough colors informations", data));
	return (&str[i]);
}

char	*fc_check_args(char *str, t_data *data, int *color)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 0 || i > 3 || (str[i] && (str[i] != ','
				&& str[i] != ' ' && str[i] != '	')))
		exit (error_msg("colors informations are not appropriate", data));
	tmp = malloc ((i + 1) * sizeof (char));
	if (!tmp)
		exit (error_msg("malloc didn't work correctly", data));
	ft_strlcpy(tmp, str, i + 1);
	*color = atoi(tmp);
	free (tmp);
	if (*color < 0 || *color > 255)
		exit (error_msg("incorrect color number", data));
	if (!str[i])
		return (NULL);
	return (&str[i]);
}

void	*fc_check(char *str, t_data *data, t_color *fc)
{
	int		i;

	i = 0;
	if (fc->red != -1)
		exit (error_msg("duplicate colors element", data));
	if (str[1] != ' ' && str[1] != '	')
		exit (error_msg("identifier argument is not appropriate", data));
	i++;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (!str[i])
		exit (error_msg("colors informations are missing", data));
	str = fc_check_args(&str[i], data, &fc->red);
	str = fc_clean_args(str, data);
	str = fc_check_args(str, data, &fc->green);
	str = fc_clean_args(str, data);
	str = fc_check_args(str, data, &fc->blue);
	i = 0;
	while (str && str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str && str[i])
		exit (error_msg("too much colors informations", data));
	return (0);
}
