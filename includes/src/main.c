/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:45:24 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 18:13:58 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
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
	if (ft_malloc(data) == 1)
		destroy(data);
	init_map(argv[1], data->map);
	if (check_map(argv[1], data) == -1)
		destroy(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map->width * 64,
			data->map->height * 64, "so_long");
	init_texture(data);
	render_map(data, data->map);
	mlx_hook(data->win, 17, 1L << 17, &destroy, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_loop_hook(data->mlx, base_animation, data);
	mlx_loop(data->mlx);
}
