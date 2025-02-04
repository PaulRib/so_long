/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:19:39 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 19:19:44 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_map2(t_vars *data, t_map *map, int y, int x)
{
	if (map->grid[y][x] == 'C')
		put_image(data, 3, y, x);
	else if (map->grid[y][x] == 'E')
	{
		put_image(data, 4, y, x);
		data->map->exit_x = x;
		data->map->exit_y = y;
	}
	else if (map->grid[y][x] == 'D')
	{
		data->npc->p_y = y;
		data->npc->p_x = x;
		put_image(data, 6, y, x);
	}
}

void	render_map(t_vars *data, t_map *map)
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
				data->map->player_x = x;
				data->map->player_y = y;
				put_image(data, 1, y, x);
			}
			else
				render_map2(data, map, y, x);
		}
	}
}

void	put_image(t_vars *data, int type, int y, int x)
{
	if (type == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_floor, x
			* 64, y * 64);
	if (type == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->props->img_character, x * 64, y * 64);
	if (type == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_wall, x
			* 64, y * 64);
	if (type == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_item, x
			* 64, y * 64);
	if (type == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_exit[0],
			x * 64, y * 64);
	if (type == 5)
		mlx_put_image_to_window(data->mlx, data->win,
			data->props->img_character_e, x * 64, y * 64);
	if (type == 6)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_enemy, x
			* 64, y * 64);
	if (type == 7)
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_enemy_c,
			x * 64, y * 64);
}
