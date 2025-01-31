/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:22 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 18:51:22 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void 	handle_movement(int keycode, t_vars *data)
{
	if (keycode == KEY_A || keycode == LEFT)
		movement_left(data);
	else if (keycode == KEY_W || keycode == UP)
		movement_up(data);
	else if (keycode == KEY_D || keycode == RIGHT)
		movement_right(data);
	else if (keycode == KEY_S || keycode == DOWN)
		movement_down(data);
}

void 	movement_left(t_vars *data)
{
	if (check_grid(data, data->map->player_y, data->map->player_x - 1) == 0)
		return ;
	if (check_grid(data, data->map->player_y, data->map->player_x - 1) == 1)
	{
		data->map->grid[data->map->player_y][data->map->player_x - 1] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	data->map->player_x--;
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

void 	movement_right(t_vars *data)
{
	if (check_grid(data, data->map->player_y, data->map->player_x + 1) == 0)
		return ;
	if (check_grid(data, data->map->player_y, data->map->player_x + 1) == 1)
	{
		data->map->grid[data->map->player_y][data->map->player_x + 1] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	data->map->player_x++;
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

void 	movement_down(t_vars *data)
{
	if (check_grid(data, data->map->player_y + 1, data->map->player_x) == 0)
		return ;
	if (check_grid(data, data->map->player_y + 1, data->map->player_x) == 1)
	{
		data->map->grid[data->map->player_y + 1][data->map->player_x] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	data->map->player_y++;
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

void 	movement_up(t_vars *data)
{
	if (check_grid(data, data->map->player_y - 1, data->map->player_x) == 0)
		return ;
	if (check_grid(data, data->map->player_y - 1, data->map->player_x) == 1)
	{
		data->map->grid[data->map->player_y - 1][data->map->player_x] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	data->map->player_y--;
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

int check_grid(t_vars *data, int y, int x)
{
	if (data->map->grid[y][x] == '1')
		return (0);
	else if (data->map->grid[y][x] == 'C')
		return (1);
	else if(data->map->grid[y][x] == 'E')
		return (2);
	else
		return (3);
}

void put_image(t_vars *data, int type, int y, int x)
{
	if (type == 0)
		mlx_put_image_to_window(data->mlx, data->win,
								data->props->img_floor, x * 64, y * 64);
	if (type == 1)
		mlx_put_image_to_window(data->mlx, data->win,
								data->props->img_character, x * 64, y * 64);
	if (type == 2)
		mlx_put_image_to_window(data->mlx, data->win,
								data->props->img_wall, x * 64, y * 64);
	if (type == 3)
		mlx_put_image_to_window(data->mlx, data->win,
								data->props->img_item, x * 64, y * 64);
	if (type == 4)
		mlx_put_image_to_window(data->mlx, data->win,
								data->props->img_exit, x * 64, y * 64);
	if (type == 5)
	mlx_put_image_to_window(data->mlx, data->win,
							data->props->img_character_e, x * 64, y * 64);
}
