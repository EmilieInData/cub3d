/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:14:24 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3D.h"

int main(int argc, char **argv)
{	
	t_data *data;

	data = NULL;
	if (argc != 2)
		ft_exit(1, "Error, wrong number of arguments\n");
	if (argc == 2 && (is_cub(argv[1]) == 0))
	{
		init_map(data);
		find_wall(data);
		//mlx_functions(game);
	}
	return (0);
}

void	ft_exit(int ex_stat, char *message)
{
	printf("%s\n", message);
	exit(ex_stat);
}

int is_cub(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 1;
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'c' && argv[i - 1] == 'u'
			&& argv[i] == 'b'))
		{
			ft_exit(1, "error");
			return(1);
		}
	else
		return (0);
}
