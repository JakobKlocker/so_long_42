/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:28:59 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/11 12:50:14 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_info;
	int		fd;

	if (map_handling(argc, argv, &map_info))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_msg());
	read_map_2d_copy(&map_info, fd);
	graphic_open_window(&map_info);
	return (0);
}
