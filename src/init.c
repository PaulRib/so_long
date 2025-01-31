/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:53:17 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 20:21:59 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void 	init_texture(t_vars *data)
{
	data->props->height = 64;
	data->props->width = 64;
	data->props->wall = "./asset/wall.xpm";
	data->props->floor = "./asset/floor.xpm";
	data->props->character = "./asset/character.xpm";
	data->props->exit = "./asset/exit.xpm";
	data->props->item = "./asset/item.xpm";
	data->props->character_e = "./asset/character_e.xpm";
	data->props->img_wall = mlx_xpm_file_to_image(data->mlx, data->props->wall,
							&(data->props->width), &(data->props->height));
	data->props->img_floor = mlx_xpm_file_to_image(data->mlx, data->props->floor,
							&(data->props->width), &(data->props->height));
	data->props->img_character = mlx_xpm_file_to_image(data->mlx, data->props->character,
							&(data->props->width), &(data->props->height));
	data->props->img_exit = mlx_xpm_file_to_image(data->mlx, data->props->exit,
							&(data->props->width), &(data->props->height));
	data->props->img_item = mlx_xpm_file_to_image(data->mlx, data->props->item,
							&(data->props->width), &(data->props->height));
	data->props->img_character_e = mlx_xpm_file_to_image(data->mlx, data->props->character_e,
							&(data->props->width), &(data->props->height));
							
}

void init_map(char *filename, t_map *map)
{
	int 	fd;
	int 	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	map->height = 0;
	get_height(map, fd);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return ;
	close(fd);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (1)
	{
		map->grid[i] = get_next_line(fd);
		if (map->grid[i] == NULL)
			break ;
		i++;
	}
	map->width = ft_strlen(map->grid[0]) - 1;
	close(fd);
	return ;
}

void render_map(t_vars *data, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == '1')
				put_image(data, 2, y, x);
			else if (map->grid[y][x] == '0')
				put_image(data, 0, y, x);
			else if (map->grid[y][x] == 'P')
			{
				put_image(data, 1, y, x);
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'C')
				put_image(data, 3, y, x);
			else if (map->grid[y][x] == 'E')
				put_image(data, 4, y, x);
		}
	}
}
