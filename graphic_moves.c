/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:48:41 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/11 12:01:48 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_hook(int key, t_map *map_info)
{
	if (key == XK_Right || key == XK_d)
		move_right(map_info);
	if (key == XK_Left || key == XK_a)
		move_left(map_info);
	if (key == XK_Up || key == XK_w)
		move_up(map_info);
	if (key == XK_Down || key == XK_s)
		move_down(map_info);
	if (key == XK_Escape)
		close_game(map_info);
	return (0);
}

void	move_right(t_map *map_info)
{
	if (map_info->map_2d_copy[map_info->player_x][map_info->player_y + 1] == '0'
		|| map_info->map_2d_copy[map_info->player_x][map_info->player_y
		+ 1] == 'C')
	{
		if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
			+ 1] == 'C')
			map_info->collectible--;
		map_info->map_2d_copy[map_info->player_x][map_info->player_y + 1] = 'P';
		map_info->map_2d_copy[map_info->player_x][map_info->player_y] = '0';
		map_info->player_y++;
		map_info->move_counter++;
		ft_printf("%i\n", map_info->move_counter);
		draw_map_once(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
		+ 1] == 'E' && map_info->collectible == 0)
	{
		ft_printf("You Won!!");
		close_game(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
		+ 1] == 'E' && map_info->collectible != 0)
		ft_printf("Destroy all Pawns!!\n");
}

void	move_left(t_map *map_info)
{
	if (map_info->map_2d_copy[map_info->player_x][map_info->player_y - 1] == '0'
		|| map_info->map_2d_copy[map_info->player_x][map_info->player_y
		- 1] == 'C')
	{
		if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
			- 1] == 'C')
			map_info->collectible--;
		map_info->map_2d_copy[map_info->player_x][map_info->player_y - 1] = 'P';
		map_info->map_2d_copy[map_info->player_x][map_info->player_y] = '0';
		map_info->player_y--;
		map_info->move_counter++;
		ft_printf("%i\n", map_info->move_counter);
		draw_map_once(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
		- 1] == 'E' && map_info->collectible == 0)
	{
		ft_printf("You Won!!");
		close_game(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x][map_info->player_y
		- 1] == 'E' && map_info->collectible != 0)
		ft_printf("Destroy all Pawns!!\n");
}

void	move_up(t_map *map_info)
{
	if (map_info->map_2d_copy[map_info->player_x - 1][map_info->player_y] == '0'
		|| map_info->map_2d_copy[map_info->player_x
		- 1][map_info->player_y] == 'C')
	{
		if (map_info->map_2d_copy[map_info->player_x
				- 1][map_info->player_y] == 'C')
			map_info->collectible--;
		map_info->map_2d_copy[map_info->player_x - 1][map_info->player_y] = 'P';
		map_info->map_2d_copy[map_info->player_x][map_info->player_y] = '0';
		map_info->player_x--;
		map_info->move_counter++;
		ft_printf("%i\n", map_info->move_counter);
		draw_map_once(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x
			- 1][map_info->player_y] == 'E' && map_info->collectible == 0)
	{
		ft_printf("You Won!!");
		close_game(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x
			- 1][map_info->player_y] == 'E' && map_info->collectible != 0)
		ft_printf("Destroy all Pawns!!\n");
}

void	move_down(t_map *map_info)
{
	if (map_info->map_2d_copy[map_info->player_x + 1][map_info->player_y] == '0'
		|| map_info->map_2d_copy[map_info->player_x
		+ 1][map_info->player_y] == 'C')
	{
		if (map_info->map_2d_copy[map_info->player_x
				+ 1][map_info->player_y] == 'C')
			map_info->collectible--;
		map_info->map_2d_copy[map_info->player_x + 1][map_info->player_y] = 'P';
		map_info->map_2d_copy[map_info->player_x][map_info->player_y] = '0';
		map_info->player_x++;
		map_info->move_counter++;
		ft_printf("%i\n", map_info->move_counter);
		draw_map_once(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x
			+ 1][map_info->player_y] == 'E' && map_info->collectible == 0)
	{
		ft_printf("You Won!!");
		close_game(map_info);
	}
	else if (map_info->map_2d_copy[map_info->player_x
			+ 1][map_info->player_y] == 'E' && map_info->collectible != 0)
		ft_printf("Destroy all Pawns!!\n");
}
