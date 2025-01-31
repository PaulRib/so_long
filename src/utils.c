/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:46 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 19:55:49 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int get_height(t_map *map, int fd)
{
	char *line;
	
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->height++;
		free(line);
	}
	free(line);
	return (map->height);
}

int	ft_malloc(t_vars *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	data->props = malloc(sizeof(t_props));
	if (!data->props)
		return (1);
	data->item = malloc(sizeof(t_count));
	if (!data->item)
		return (1);
	ft_memset(data->item, 0, sizeof(t_count));
	return (0);
}

void free_images(t_vars *data)
{
    if (data->props->img_wall)
        mlx_destroy_image(data->mlx, data->props->img_wall);
    if (data->props->img_floor)
        mlx_destroy_image(data->mlx, data->props->img_floor);
    if (data->props->img_character)
        mlx_destroy_image(data->mlx, data->props->img_character);
    if (data->props->img_exit)
        mlx_destroy_image(data->mlx, data->props->img_exit);
    if (data->props->img_item)
		mlx_destroy_image(data->mlx, data->props->img_item);
	if (data->props->img_character_e)
        mlx_destroy_image(data->mlx, data->props->img_character_e);
}

void 	ft_free_all(t_vars *data)
{
	if (data->map)
	{
		if (data->map->grid)
			free_tab(data->map->grid);
		free(data->map);
	}
	if (data->item)
		free(data->item);
	if (data->mlx)
	{
		free_images(data);
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
	}
	if (data->props)
		free(data->props);
}

int	valid_file(char *filename)
{
	if (ft_strstr(filename, ".ber") != 0)
		return (0);
	return (1);
}
