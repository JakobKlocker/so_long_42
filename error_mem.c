/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:44:09 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/11 12:51:07 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->row)
	{
		if (map_info->map_2d[i] != NULL)
			free(map_info->map_2d[i]);
		if (map_info->map_2d_copy[i] != NULL)
			free(map_info->map_2d_copy[i]);
		map_info->map_2d[i] = NULL;
		map_info->map_2d_copy[i] = NULL;
	}
	if (map_info->map_1d != NULL)
		free(map_info->map_1d);
	if (map_info->map_2d != NULL)
		free(map_info->map_2d);
	if (map_info->map_2d_copy != NULL)
		free(map_info->map_2d_copy);
	map_info->map_1d = NULL;
	map_info->map_2d = NULL;
	map_info->map_2d_copy = NULL;
}

void	close_game(t_map *map_info)
{
	mlx_destroy_display(map_info->mlx.mlx);
	free_all(map_info);
	exit(0);
}

int	hook_esc(t_map *map_info)
{
	(void)map_info;
	close_game(map_info);
	return (0);
}
