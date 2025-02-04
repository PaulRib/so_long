/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:06:49 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:24 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	line_checker(char *line, t_vars *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			data->item->collectible++;
		if (line[i] == 'E')
			data->item->exit++;
		if (line[i] == 'P')
			data->item->start++;
		if (line[i] == 'D')
			data->npc->is = 1;
		i++;
	}
}

void	get_height(t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->height++;
		free(line);
	}
	free(line);
}

int	check_grid(t_vars *data, int y, int x)
{
	if (data->map->grid[y][x] == '1')
		return (0);
	else if (data->map->grid[y][x] == 'C')
		return (1);
	else if (data->map->grid[y][x] == 'E')
		return (2);
	else
		return (3);
}

void	show_movement(t_vars *data)
{
	char	*count_movement;

	data->player->move++;
	mlx_put_image_to_window(data->mlx, data->win, data->props->img_wall, 0, 0);
	count_movement = ft_strjoin("Move: ", ft_itoa(data->player->move));
	mlx_string_put(data->mlx, data->win, 5, 20, 0xffffff, count_movement);
	free(count_movement);
}

int	valid_file(char *filename)
{
	if (ft_strstr(filename, ".ber") != 0)
		return (0);
	return (1);
}
