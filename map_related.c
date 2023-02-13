/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:01:00 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/10 14:18:47 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_handling(int argc, char **argv, t_map *map_info)
{
	int	fd;

	if (check_argv(argc, argv[1]) == -1)
		return (error_msg());
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_msg());
	if (read_map_1d(map_info, fd) == -1)
		return (error_msg());
	zero_map_info(map_info);
	if (get_row_colum(map_info) == -1)
		return (error_msg());
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_msg());
	read_map_2d(map_info, fd);
	if (check_map_info(map_info) == -1)
		return (error_msg());
	return (0);
}

int	check_map_info(t_map *map_info)
{
	init_map_info(map_info);
	if (map_info->collectible <= 0 || map_info->players != 1
		|| map_info->exits != 1 || map_info->invalid_char != 0)
		return (-1);
	if (is_rectang(map_info) == -1)
		return (-1);
	if (sur_walls(map_info) == -1)
		return (-1);
	valid_path(map_info);
	if (map_info->valid_path == 0)
		return (-1);
	return (0);
}

void	zero_map_info(t_map *map_info)
{
	map_info->column = 0;
	map_info->row = 0;
	map_info->collectible = 0;
	map_info->players = 0;
	map_info->exits = 0;
	map_info->invalid_char = 0;
	map_info->valid_path = 0;
	map_info->move_counter = 0;
}

void	print_map(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->row)
	{
		ft_printf("%s\n", map_info->map_2d[i]);
	}
	write(1, "\n", 1);
}

void	print_map_copy(t_map *map_info)
{
	int	i;

	i = -1;
	while (++i < map_info->row)
	{
		ft_printf("%s\n", map_info->map_2d_copy[i]);
	}
	write(1, "\n", 1);
}
