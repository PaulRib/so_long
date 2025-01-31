/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:45:24 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 20:09:32 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	handle_key(int keycode, t_vars *data)
{
	if (keycode >= 65361 && keycode <= 65364)
		handle_movement(keycode, data);
	if (keycode == KEY_W || keycode == KEY_A 
		|| keycode == KEY_S || keycode == KEY_D)
		handle_movement(keycode, data);
	if (keycode == KEY_ESC)
		destroy(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	*data;
	
	if (argc != 2 || valid_file(argv[1]))
	{
		ft_putstr_fd("Usage : ./so_long + location of map.ber\n", 2);
		exit(1);
	}
	data = malloc(sizeof(t_vars));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_vars));
	ft_malloc(data);
	init_map(argv[1], data->map);
	if (check_map(argv[1], data) == -1)
		destroy(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "so_long");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	init_texture(data);
	render_map(data, data->map);
	mlx_hook(data->win, 17, 1L<<17, &destroy, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop(data->mlx);
}
