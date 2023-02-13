/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:16:49 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/09 18:28:12 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_info(t_map *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (map_info->row > ++i)
	{
		j = -1;
		while (map_info->map_2d[i][++j])
		{
			if (map_info->map_2d[i][j] == 'P')
			{
				map_info->players = map_info->players + 1;
				map_info->player_x = i;
				map_info->player_y = j;
			}
			if (map_info->map_2d[i][j] == 'C')
				map_info->collectible = map_info->collectible + 1;
			if (map_info->map_2d[i][j] == 'E')
				map_info->exits = map_info->exits + 1;
			invalid_check(map_info, i, j);
		}
	}
}

void	path_first_x(t_map *map_info)
{
	if (map_info->map_2d[map_info->player_x - 1][map_info->player_y] == '0'
		|| map_info->map_2d[map_info->player_x - 1][map_info->player_y] == 'C')
		map_info->map_2d[map_info->player_x - 1][map_info->player_y] = 'X';
	if (map_info->map_2d[map_info->player_x + 1][map_info->player_y] == '0'
		|| map_info->map_2d[map_info->player_x + 1][map_info->player_y] == 'C')
		map_info->map_2d[map_info->player_x + 1][map_info->player_y] = 'X';
	if (map_info->map_2d[map_info->player_x - 1][map_info->player_y] == '0'
		|| map_info->map_2d[map_info->player_x - 1][map_info->player_y] == 'C')
		map_info->map_2d[map_info->player_x - 1][map_info->player_y] = 'X';
	if (map_info->map_2d[map_info->player_x][map_info->player_y + 1] == '0'
		|| map_info->map_2d[map_info->player_x][map_info->player_y + 1] == 'C')
		map_info->map_2d[map_info->player_x][map_info->player_y + 1] = 'X';
}

void	path_exit_next_player(t_map *map_info)
{
	if (map_info->map_2d[map_info->player_x - 1][map_info->player_y] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[map_info->player_x + 1][map_info->player_y] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[map_info->player_x][map_info->player_y - 1] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[map_info->player_x][map_info->player_y + 1] == 'E')
		map_info->valid_path = 1;
}

void	path_check_surroundings(t_map *map_info, int j, int k)
{
	if (map_info->map_2d[j - 1][k] == '0' || map_info->map_2d[j - 1][k] == 'C')
		map_info->map_2d[j - 1][k] = 'X';
	if (map_info->map_2d[j + 1][k] == '0' || map_info->map_2d[j + 1][k] == 'C')
		map_info->map_2d[j + 1][k] = 'X';
	if (map_info->map_2d[j][k - 1] == '0' || map_info->map_2d[j][k - 1] == 'C')
		map_info->map_2d[j][k - 1] = 'X';
	if (map_info->map_2d[j][k + 1] == '0' || map_info->map_2d[j][k + 1] == 'C')
		map_info->map_2d[j][k + 1] = 'X';
	if (map_info->map_2d[j - 1][k] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[j + 1][k] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[j][k - 1] == 'E')
		map_info->valid_path = 1;
	if (map_info->map_2d[j][k + 1] == 'E')
		map_info->valid_path = 1;
}

//Bruach noch map Copie
void	valid_path(t_map *map_info)
{
	int	i;
	int	j;
	int	k;

	path_first_x(map_info);
	i = -1;
	while (++i < (map_info->column - 2) * (map_info->row - 2)
		&& map_info->valid_path == 0)
	{
		j = -1;
		while (++j < map_info->row)
		{
			k = -1;
			while (++k < map_info->column)
			{
				if (map_info->map_2d[j][k] == 'X')
				{
					path_check_surroundings(map_info, j, k);
				}
			}
		}
	}
}
