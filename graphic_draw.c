/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:45:54 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/11 12:51:35 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	graphic_open_window(t_map *map_info)
{
	map_info->mlx.mlx = mlx_init();
	map_info->mlx.win = mlx_new_window(map_info->mlx.mlx, map_info->column
			* PIX, map_info->row * PIX, "It's ... so Long!");
	if (handle_drawing(map_info) == -1)
	{
		ft_printf("Image not Found.");
		return (-1);
	}
	mlx_loop(map_info->mlx.mlx);
	return (0);
}

int	handle_drawing(t_map *map_info)
{
	int	i;

	map_info->obj.player.addr = XP(map_info->mlx.mlx, "./img/plr.xpm", &i,
			&i);
	map_info->obj.collect.addr = XP(map_info->mlx.mlx, "./img/col.xpm", &i,
			&i);
	map_info->obj.exit.addr = XP(map_info->mlx.mlx, "./img/ext.xpm", &i, &i);
	map_info->obj.wall.addr = XP(map_info->mlx.mlx, "./img/wall.xpm", &i, &i);
	map_info->obj.space.addr = XP(map_info->mlx.mlx, "./img/gras.xpm", &i, &i);
	if (map_info->obj.player.addr == NULL || map_info->obj.collect.addr == NULL
		|| map_info->obj.exit.addr == NULL || map_info->obj.wall.addr == NULL
		|| map_info->obj.space.addr == NULL)
		return (-1);
	mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
		map_info->obj.player.addr, map_info->player_y * PIX,
		map_info->player_x * PIX);
	draw_map_once(map_info);
	draw_loop(map_info);
	return (0);
}

void	draw_map_once_checks(t_map *map_info, int i, int j)
{
	if (map_info->map_2d_copy[i][j] == '0')
		mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
			map_info->obj.space.addr, j * PIX, i * PIX);
	if (map_info->map_2d_copy[i][j] == '1')
		mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
			map_info->obj.wall.addr, j * PIX, i * PIX);
	if (map_info->map_2d_copy[i][j] == 'P')
		mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
			map_info->obj.player.addr, j * PIX, i * PIX);
	if (map_info->map_2d_copy[i][j] == 'C')
		mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
			map_info->obj.collect.addr, j * PIX, i * PIX);
	if (map_info->map_2d_copy[i][j] == 'E')
		mlx_put_image_to_window(map_info->mlx.mlx, map_info->mlx.win,
			map_info->obj.exit.addr, j * PIX, i * PIX);
}

void	draw_map_once(t_map *map_info)
{
	int	i;
	int	j;

	i = -1;
	while (map_info->row > ++i)
	{
		j = -1;
		while (map_info->column > ++j)
		{
			draw_map_once_checks(map_info, i, j);
		}
	}
}

int	draw_loop(t_map *map_info)
{
	mlx_key_hook(map_info->mlx.win, &move_hook, map_info);
	mlx_hook(map_info->mlx.win, 17, 0, &hook_esc, map_info);
	mlx_loop(map_info->mlx.mlx);
	return (0);
}
