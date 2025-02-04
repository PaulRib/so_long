/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:56:19 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 19:26:08 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int get_pos_y(t_vars *data, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			if (data->map->grid[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int get_pos_x(t_vars *data, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			if (data->map->grid[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_flood(char **map, t_vars *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '\n')
				break;
			if (map[y][x] != 'F' && map[y][x] != '1' && map[y][x] != '0')
			{
				free_tab(map);
				return (-1);
			}
			x++;
		}
		y++;
	}
	free_tab(map);
	return (0);
}

char	**flood_fill(char **map, int y, int x)
{
	map[y][x] = 'F';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood_fill(map, y + 1, x);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood_fill(map, y - 1, x);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood_fill(map, y, x + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood_fill(map, y, x - 1);
	return (map);
}
