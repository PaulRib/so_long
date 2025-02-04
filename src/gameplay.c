/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:22 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 18:15:32 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	movement_left(t_vars *data)
{
	if (check_grid(data, data->map->player_y, data->map->player_x - 1) == 0)
		return ;
	show_movement(data);
	if (check_grid(data, data->map->player_y, data->map->player_x - 1) == 1)
	{
		data->map->grid[data->map->player_y][data->map->player_x - 1] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	if (check_collision(data, 1) == 1)
		put_image(data, 6, data->map->player_y, data->map->player_x);
	data->map->player_x--;
	if (check_collision(data, 0) == 1)
		put_image(data, 7, data->map->player_y, data->map->player_x);
	else if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

static void	movement_right(t_vars *data)
{
	if (check_grid(data, data->map->player_y, data->map->player_x + 1) == 0)
		return ;
	show_movement(data);
	if (check_grid(data, data->map->player_y, data->map->player_x + 1) == 1)
	{
		data->map->grid[data->map->player_y][data->map->player_x + 1] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	if (check_collision(data, 1) == 1)
		put_image(data, 6, data->map->player_y, data->map->player_x);
	data->map->player_x++;
	if (check_collision(data, 0) == 1)
		put_image(data, 7, data->map->player_y, data->map->player_x);
	else if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

static void	movement_down(t_vars *data)
{
	if (check_grid(data, data->map->player_y + 1, data->map->player_x) == 0)
		return ;
	show_movement(data);
	if (check_grid(data, data->map->player_y + 1, data->map->player_x) == 1)
	{
		data->map->grid[data->map->player_y + 1][data->map->player_x] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	if (check_collision(data, 1) == 1)
		put_image(data, 6, data->map->player_y, data->map->player_x);
	data->map->player_y++;
	if (check_collision(data, 0) == 1)
		put_image(data, 7, data->map->player_y, data->map->player_x);
	else if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

static void	movement_up(t_vars *data)
{
	if (check_grid(data, data->map->player_y - 1, data->map->player_x) == 0)
		return ;
	show_movement(data);
	if (check_grid(data, data->map->player_y - 1, data->map->player_x) == 1)
	{
		data->map->grid[data->map->player_y - 1][data->map->player_x] = '0';
		data->item->collectible--;
	}
	if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
		put_image(data, 4, data->map->player_y, data->map->player_x);
	else
		put_image(data, 0, data->map->player_y, data->map->player_x);
	if (check_collision(data, 1) == 1)
		put_image(data, 6, data->map->player_y, data->map->player_x);
	data->map->player_y--;
	if (check_collision(data, 0) == 1)
		put_image(data, 7, data->map->player_y, data->map->player_x);
	else if (check_grid(data, data->map->player_y, data->map->player_x) == 2)
	{
		put_image(data, 5, data->map->player_y, data->map->player_x);
		if (data->item->collectible == 0)
			destroy(data);
	}
	else
		put_image(data, 1, data->map->player_y, data->map->player_x);
}

int	handle_key(int keycode, t_vars *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	if (keycode == KEY_A || keycode == LEFT)
		movement_left(data);
	else if (keycode == KEY_W || keycode == UP)
		movement_up(data);
	else if (keycode == KEY_D || keycode == RIGHT)
		movement_right(data);
	else if (keycode == KEY_S || keycode == DOWN)
		movement_down(data);
	return (0);
}
