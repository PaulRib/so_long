/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:51:55 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/30 15:00:15 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map *init_map(char *filename, t_map *map)
{
	int 	fd;
	int 	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map->height = 0;
	while (get_next_line(fd) != NULL)
		map->height++;
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (NULL);
	close(fd);
	fd = open(filename, O_RDONLY);
	i = 0;
	map->grid[i] = get_next_line(fd);
	map->width = ft_strlen(map->grid[i]);
	i++;
	while (1)
	{
		map->grid[i] = get_next_line(fd);
		if (map->grid[i] == NULL)
			break ;
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	return (map);
}

void render_map(t_vars *data, t_map *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_wall, x * 64, y * 64);
			else if (map->grid[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_floor, x * 64, y * 64);
			else if (map->grid[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_floor, x * 64, y * 64);
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_character, x * 64, y * 64);
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_floor, x * 64, y * 64);
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_item, x * 64, y * 64);
			}
			else if (map->grid[y][x] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_floor, x * 64, y * 64);
				mlx_put_image_to_window(data->mlx, data->win, data->props->img_exit, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}
