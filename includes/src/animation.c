/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:47:20 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:01 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	enemy_move(t_vars *data, int sense)
{
	if (sense == 0)
	{
		if (check_grid(data, data->npc->p_y + 1, data->npc->p_x) == 3)
		{
			if (check_collision(data, 1) == 1)
				put_image(data, 1, data->map->player_y, data->map->player_x);
			else
				put_image(data, 0, data->npc->p_y, data->npc->p_x);
			data->npc->p_y++;
			put_image(data, 6, data->npc->p_y, data->npc->p_x);
		}
	}
	else if (sense == 1)
	{
		if (check_grid(data, data->npc->p_y - 1, data->npc->p_x) == 3)
		{
			if (check_collision(data, 1) == 1)
				put_image(data, 1, data->map->player_y, data->map->player_x);
			else
				put_image(data, 0, data->npc->p_y, data->npc->p_x);
			data->npc->p_y--;
			put_image(data, 6, data->npc->p_y, data->npc->p_x);
		}
	}
}

static void	enemy_routine(t_vars *data)
{
	static int	sense = 0;

	if (sense == 0)
	{
		enemy_move(data, sense);
		check_collision(data, 0);
		if (check_grid(data, data->npc->p_y + 1, data->npc->p_x) != 3)
			sense = 1;
	}
	else if (sense == 1)
	{
		enemy_move(data, sense);
		check_collision(data, 0);
		if (check_grid(data, data->npc->p_y - 1, data->npc->p_x) != 3)
			sense = 0;
	}
}

int	check_collision(t_vars *data, int sense)
{
	if (data->npc->p_y == data->map->player_y
		&& data->npc->p_x == data->map->player_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->props->img_enemy_c,
			data->npc->p_x * 64, data->npc->p_y * 64);
		if (sense == 0)
			data->player->life--;
		if (data->player->life == 0)
			destroy(data);
		return (1);
	}
	return (0);
}

static void	render_animation(t_vars *data)
{
	static int	i = 0;

	if (i <= 5)
	{
		if (data->map->exit_x != data->map->player_x
			|| data->map->exit_y != data->map->player_y)
			mlx_put_image_to_window(data->mlx, data->win,
				data->props->img_exit[i], data->map->exit_x * 64,
				data->map->exit_y * 64);
		i++;
	}
	else
		i = 0;
}

int	base_animation(t_vars *data)
{
	static int	time = 0;

	if (time == 10000)
		render_animation(data);
	if (++time < 15000)
		return (0);
	time = 0;
	if (data->npc->is != 0)
		enemy_routine(data);
	render_animation(data);
	return (0);
}
