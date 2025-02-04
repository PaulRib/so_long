/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:46 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 18:19:56 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_free_animation(t_vars *data)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		mlx_destroy_image(data->mlx, data->props->img_exit[i]);
		i++;
	}
}

static void	free_images(t_vars *data)
{
	if (data->props->img_wall)
		mlx_destroy_image(data->mlx, data->props->img_wall);
	if (data->props->img_floor)
		mlx_destroy_image(data->mlx, data->props->img_floor);
	if (data->props->img_character)
		mlx_destroy_image(data->mlx, data->props->img_character);
	if (data->props->img_exit)
		ft_free_animation(data);
	if (data->props->img_item)
		mlx_destroy_image(data->mlx, data->props->img_item);
	if (data->props->img_character_e)
		mlx_destroy_image(data->mlx, data->props->img_character_e);
	if (data->props->img_enemy)
		mlx_destroy_image(data->mlx, data->props->img_enemy);
	if (data->props->img_enemy_c)
		mlx_destroy_image(data->mlx, data->props->img_enemy_c);
}

static void	ft_free_all(t_vars *data)
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
	if (data->player)
		free(data->player);
	if (data->npc)
		free(data->npc);
}

int	destroy(t_vars *data)
{
	ft_free_all(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data)
		free(data);
	exit(1);
}
