/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:14 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/05 18:18:36 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_props(char *filename, t_vars *data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_checker(line, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (data->item->collectible <= 0 || data->item->exit != 1
		|| data->item->start != 1)
		return (-1);
	return (0);
}

static int	check_form(t_vars *data)
{
	int	x;
	int	y;
	int	first_x;

	first_x = 0;
	y = -1;
	x = 0;
	while (++y < data->map->height)
	{
		while (data->map->grid[y][x])
		{
			if (data->map->grid[y][x] == '\n')
				break ;
			x++;
		}
		if (first_x != 0)
		{
			if (first_x != x)
				return (-1);
		}
		first_x = x;
		x = 0;
	}
	return (0);
}

static int	check_close(t_vars *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->map->width)
		if (data->map->grid[0][x] != '1')
			return (-1);
	x = -1;
	while (++x < data->map->width)
		if (data->map->grid[data->map->height - 1][x] != '1')
			return (-1);
	y = -1;
	while (++y < data->map->height)
		if (data->map->grid[y][0] != '1')
			return (-1);
	y = -1;
	while (++y < data->map->height)
		if (data->map->grid[y][data->map->width - 1] != '1')
			return (-1);
	return (0);
}

static int check_valid_path(char *filename, t_vars *data)
{
	char	**copy;
	int		fd;
	int		i;
	int		y;
	int		x;

	i = 0;
	fd = open(filename, O_RDONLY);
	copy = malloc(sizeof(char *) * (data->map->height + 1));
	if (!copy)
		return (-1);
	while (1)
	{
		copy[i] = get_next_line(fd);
		if (copy[i] == NULL)
			break;
		i++;
	}
	copy[i] = NULL;
	y = get_pos_y(data, 'P');
	x = get_pos_x(data, 'P');
	copy = flood_fill(copy, y, x);
	if (check_flood(copy, data) == -1)
		return (-1);
	return (0);
}

int	check_map(char *filename, t_vars *data)
{
	if (check_props(filename, data) == -1 || check_form(data) == -1
		|| check_close(data) == -1
		|| check_valid_path(filename, data) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map not valid\n", 2);
		destroy(data);
	}
	return (0);
}
