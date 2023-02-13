/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:16:09 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/11 12:54:20 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/ft_printf.h"
# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIX 40
# define XP mlx_xpm_file_to_image

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_img
{
	void	*addr;
	int		width;
	int		height;
}			t_img;

typedef struct s_obj
{
	t_img	player;
	t_img	exit;
	t_img	collect;
	t_img	wall;
	t_img	space;
}			t_obj;

typedef struct s_map
{
	int		column;
	int		row;
	int		exits;
	int		collectible;
	int		players;
	int		invalid_char;
	char	**map_2d;
	char	**map_2d_copy;
	char	*map_1d;
	int		player_x;
	int		player_y;
	int		move_counter;
	int		valid_path;
	t_mlx	mlx;
	t_obj	obj;
}			t_map;

//Map Reading
int			read_map(t_map *map_info, char *input_name);
int			read_map_1d(t_map *map_info, int fd);
int			read_map_2d(t_map *map_info, int fd);
int			read_map_2d_copy(t_map *map_info, int fd);
int			get_row_colum(t_map *map_info);

//Argv checks
int			check_argv(int argc, char *argv);

//Map checks
void		valid_path(t_map *map_info);
void		zero_map_info(t_map *map_info);
void		init_map_info(t_map *map_info);
int			is_rectang(t_map *map_info);
int			sur_walls(t_map *map_info);
int			check_map_info(t_map *map_info);
void		path_first_x(t_map *map_info);
int			map_handling(int argc, char **argv, t_map *map_info);
void		invalid_check(t_map *map_info, int i, int j);

//Error
int			error_msg(void);
int			hook_esc(t_map *map_info);

//Print Map
void		print_map(t_map *map_info);
void		print_map_copy(t_map *map_info);

// Graphics
int			graphic_open_window(t_map *map_info);
int			handle_drawing(t_map *map_info);
void		draw_map_once(t_map *map_info);
int			draw_loop(t_map *map_info);

//Moves
int			move_hook(int key, t_map *map_info);
void		move_right(t_map *map_info);
void		move_left(t_map *map_info);
void		move_up(t_map *map_info);
void		move_down(t_map *map_info);

//Checks
void		close_game(t_map *map_info);
void		free_all(t_map *map_ifno);

#endif