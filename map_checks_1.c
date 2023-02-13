/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:10 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/09 17:06:25 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_check(t_map *map_info, int i, int j)
{
	if (map_info->map_2d[i][j] != 'P' && map_info->map_2d[i][j] != 'C'
		&& map_info->map_2d[i][j] != 'E' && map_info->map_2d[i][j] != '0'
		&& map_info->map_2d[i][j] != '1')
		map_info->invalid_char = 1;
}

int	check_argv(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (-1);
	while (argv[i])
		i++;
	if (i < 4)
		return (-1);
	if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i
			- 4] != '.')
		return (-1);
	return (0);
}

int	is_rectang(t_map *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->row)
	{
		j = 0;
		while (map_info->map_2d[i][j])
			j++;
		if (map_info->column != j)
			return (-1);
	}
	return (0);
}

int	sur_walls(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->row)
	{
		if (map_info->map_2d[i][0] != '1'
			|| map_info->map_2d[i][map_info->column - 1] != '1')
			return (-1);
	}
	i = -1;
	while (map_info->map_2d[0][++i])
	{
		if (map_info->map_2d[0][i] != '1')
			return (-1);
	}
	i = -1;
	while (map_info->map_2d[map_info->row - 1][++i])
	{
		if (map_info->map_2d[map_info->row - 1][i] != '1')
			return (-1);
	}
	return (0);
}
