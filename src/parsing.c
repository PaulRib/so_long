/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:14 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 20:28:06 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char *filename, t_vars *data)
{
	if (check_props(filename, data) == 1)
		return (-1);
	// check_valid_path(argc, argv);
	return (0);
}

int	check_props(char *filename, t_vars *data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_checker(line, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (data->item->collectible <= 0 || data->item->exit != 1
		|| data->item->start != 1 || check_form(data) == -1
		|| check_close(data) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map not valid\n", 2);
		exit(1);
	}
	return (0);
}

int	check_form(t_vars *data)
{
	int	x;
	int	y;
	int	first_x;
	int	height;

	x = 0;
	y = -1;
	first_x = 0;
	height = data->map->height;
	while (++y < height)
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
	}
	return (0);
}

int	check_close(t_vars *data)
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

void	line_checker(char *line, t_vars *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			data->item->collectible++;
		if (line[i] == 'E')
			data->item->exit++;
		if (line[i] == 'P')
			data->item->start++;
		i++;
	}
}
