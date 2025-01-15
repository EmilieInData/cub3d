/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/14 16:21:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3D.h"

int main(int argc, char **argv)
{	
	t_game *game;

	if (argc != 2)
		ft_exit(1, "Error, wrong number of arguments\n");
	if (argc == 2 && (is_cub(argv[1]) == 0))
	{
		game = malloc(sizeof(t_game));
		if (!game)
			return (0);
		game->height = 200 * 4; //800
		game->width = 320 * 4; //1280
		find_wall(game);
		mlx_functions(game);
	}
	return (0);
}

void	ft_exit(int ex_stat, char *message)
{
	ft_printf(message);
	exit(ex_stat);
}

int is_cub(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 1;
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'c' && argv[i - 1] == 'u'
			&& argv[i] == 'b'))
		ft_exit(1, "Map format is incorrect\n");
	else
		return (0);
}
