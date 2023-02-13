/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:33:25 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/10 14:19:33 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_1d(t_map *map_info, int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*tmp;

	map_info->map_1d = ft_calloc(1, 1);
	buffer = ft_calloc(1337 + 1, 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1337);
		if (bytes_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(map_info->map_1d, buffer);
		free(map_info->map_1d);
		map_info->map_1d = tmp;
	}
	free(buffer);
	close(fd);
	return (0);
}

int	read_map_2d(t_map *map_info, int fd)
{
	int	i;

	i = 0;
	map_info->map_2d = malloc(sizeof(char *) * (map_info->row + 1));
	if (map_info->map_2d == NULL)
		return (-1);
	while (i < map_info->row)
	{
		map_info->map_2d[i] = get_next_line(fd);
		if (map_info->map_2d[i] == NULL)
			return (-1);
		i++;
	}
	map_info->map_2d[map_info->row] = NULL;
	return (0);
}

int	read_map_2d_copy(t_map *map_info, int fd)
{
	int	i;

	i = 0;
	map_info->map_2d_copy = malloc(sizeof(char *) * (map_info->row + 1));
	if (map_info->map_2d_copy == NULL)
		return (-1);
	while (i < map_info->row)
	{
		map_info->map_2d_copy[i] = get_next_line(fd);
		if (map_info->map_2d_copy[i] == NULL)
			return (-1);
		i++;
	}
	map_info->map_2d_copy[map_info->row] = NULL;
	return (0);
}

int	get_row_colum(t_map *map_info)
{
	int	i;

	i = -1;
	while (map_info->map_1d[++i])
	{
		if (map_info->map_1d[i] == '\n')
			map_info->row++;
		if (map_info->map_1d[i] == '\n' && map_info->column == 0)
			map_info->column = i;
	}
	if (map_info->map_1d[0] != '\0')
		map_info->row++;
	if (i / map_info->row != map_info->column)
		return (-1);
	return (0);
}

int	error_msg(void)
{
	ft_putstr_fd("Error\nInvalid Map.", 1);
	return (-1);
}
