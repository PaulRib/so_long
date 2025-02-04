/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:53:17 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 17:30:50 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_texture(t_vars *data)
{
	data->props->height = 64;
	data->props->width = 64;
	data->props->wall = "./asset/wall.xpm";
	data->props->floor = "./asset/floor.xpm";
	data->props->character = "./asset/character.xpm";
	data->props->item = "./asset/item.xpm";
	data->props->character_e = "./asset/character_e.xpm";
	data->props->img_wall = mlx_xpm_file_to_image(data->mlx, data->props->wall,
			&(data->props->width), &(data->props->height));
	data->props->img_floor = mlx_xpm_file_to_image(data->mlx,
			data->props->floor, &(data->props->width), &(data->props->height));
	data->props->img_character = mlx_xpm_file_to_image(data->mlx,
			data->props->character, &(data->props->width),
			&(data->props->height));
	data->props->img_item = mlx_xpm_file_to_image(data->mlx, data->props->item,
			&(data->props->width), &(data->props->height));
	data->props->img_character_e = mlx_xpm_file_to_image(data->mlx,
			data->props->character_e, &(data->props->width),
			&(data->props->height));
	init_enemy(data);
	init_animation(data);
}

void	init_enemy(t_vars *data)
{
	data->props->enemy = "./asset/enemy.xpm";
	data->props->enemy_c = "./asset/enemy_c.xpm";
	data->props->img_enemy_c = mlx_xpm_file_to_image(data->mlx,
			data->props->enemy_c, &(data->props->width),
			&(data->props->height));
	data->props->img_enemy = mlx_xpm_file_to_image(data->mlx,
			data->props->enemy, &(data->props->width), &(data->props->height));
}

void	init_animation(t_vars *data)
{
	data->props->exit[0] = "./asset/exit0.xpm";
	data->props->exit[1] = "./asset/exit1.xpm";
	data->props->exit[2] = "./asset/exit2.xpm";
	data->props->exit[3] = "./asset/exit3.xpm";
	data->props->exit[4] = "./asset/exit4.xpm";
	data->props->exit[5] = "./asset/exit5.xpm";
	data->props->img_exit[0] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[0], &(data->props->width),
			&(data->props->height));
	data->props->img_exit[1] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[1], &(data->props->width),
			&(data->props->height));
	data->props->img_exit[2] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[2], &(data->props->width),
			&(data->props->height));
	data->props->img_exit[3] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[3], &(data->props->width),
			&(data->props->height));
	data->props->img_exit[4] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[4], &(data->props->width),
			&(data->props->height));
	data->props->img_exit[5] = mlx_xpm_file_to_image(data->mlx,
			data->props->exit[5], &(data->props->width),
			&(data->props->height));
}

void	init_map(char *filename, t_map *map)
{
	int	fd;
	int	i;

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
	data->player = malloc(sizeof(t_hero));
	if (!data->player)
		return (1);
	data->player->move = 0;
	data->player->life = 3;
	data->npc = malloc(sizeof(t_enemy));
	if (!data->npc)
		return (1);
	data->npc->is = 0;
	return (0);
}
