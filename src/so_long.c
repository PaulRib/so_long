/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:34:38 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/30 14:59:54 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_vars *data)
{
	if (keycode >= 65361 && keycode <= 65364)
		handle_movement(keycode, data);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		handle_movement(keycode, data);
	if (keycode == 65307)
		destroy(data);
	return (0);
}

void 	handle_movement(int keycode, t_vars *data)
{
	if (keycode == 65361 || keycode == 97)
		data->map->player_x--;
	else if (keycode == 65362 || keycode == 119)
		data->map->player_y--;
	else if (keycode == 65363 || keycode == 100)
		data->map->player_x++;
	else if (keycode == 65364 || keycode == 115)
		data->map->player_y++;
}

int	destroy(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_all(data);
	exit(1);
}

void 	init_texture(t_vars *data)
{
	data->props->height = 64;
	data->props->width = 64;
	data->props->height_c = 32;
	data->props->width_c = 32;
	data->props->wall = "./asset/wall.xpm";
	data->props->floor = "./asset/floor.xpm";
	data->props->character = "./asset/character.xpm";
	data->props->exit = "./asset/exit.xpm";
	data->props->item = "./asset/item.xpm";
	data->props->img_wall = mlx_xpm_file_to_image(data->mlx, data->props->wall,
							&(data->props->width), &(data->props->height));
	data->props->img_floor = mlx_xpm_file_to_image(data->mlx, data->props->floor,
							&(data->props->width), &(data->props->height));
	data->props->img_character = mlx_xpm_file_to_image(data->mlx, data->props->character,
							&(data->props->width), &(data->props->height));
	data->props->img_exit = mlx_xpm_file_to_image(data->mlx, data->props->exit,
							&(data->props->width), &(data->props->height));
	data->props->img_item = mlx_xpm_file_to_image(data->mlx, data->props->item,
							&(data->props->width_c), &(data->props->height_c));
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
		free(data->mlx);
	}
	free(data);
}

int	main(int argc, char **argv)
{
	t_vars	*data;

	if (argc != 2)
		return (0);
	if (check_map(argv[1]) == 1)
		return (-1);
	data = malloc(sizeof(t_vars));
	if (!data)
		return (0);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (-1);
	data->props = malloc(sizeof(t_props));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->map = init_map(argv[1], data->map);
	init_texture(data);
	render_map(data, data->map);
	mlx_hook(data->win, 17, 1L<<17, &destroy, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop(data->mlx);
}
