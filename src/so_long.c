/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:34:38 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/29 18:36:03 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_vars *data)
{
	// if (keycode >= 65361 && keycode <= 65364)
	// 	handle_movement(data);
	if (keycode == 65307)
	{
		destroy(data);
	}
	return (0);
}

// int 	handle_movement(t_vars *data)
// {

// }

int	destroy(t_vars *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(1);
}

void 	init_texture(t_vars *data)
{
	data->props.height = 32;
	data->props.width = 32;
	data->props.wall = "./asset/wall.xpm";
	data->props.floor = "./asset/floor.xpm";
	data->props.character = "./asset/character.xpm";
	data->props.exit = "./asset/exit.xpm";
	data->props.img_wall = mlx_xpm_file_to_image(data->mlx, data->props.wall,
							&(data->props.width), &(data->props.height));
	data->props.img_floor = mlx_xpm_file_to_image(data->mlx, data->props.floor,
							&(data->props.width), &(data->props.height));
	data->props.img_character = mlx_xpm_file_to_image(data->mlx, data->props.character,
							&(data->props.width), &(data->props.height));
	data->props.img_exit = mlx_xpm_file_to_image(data->mlx, data->props.exit,
							&(data->props.width), &(data->props.height));
}

int	main(int argc, char **argv)
{
	t_vars	*data;
	t_map	*map;

	if (argc != 2)
		return (0);
	if (check_map(argv[1]) == 1)
		return (-1);
	data = malloc(sizeof(t_vars));
	if (!data)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	map = init_map(argv[1], map);
	init_texture(data);
	render_map(data, map);
	mlx_hook(data->win, 17, 1L<<17, &destroy, &data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop(data->mlx);
}
