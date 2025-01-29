/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:03:58 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/29 18:13:21 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char *filename)
{
	if (check_props(filename) == 1)
		return (1);
	//check_form(argc, argv);
	//check_valid_path(argc, argv);
	return (0);
}

int	check_props(char *filename)
{
	char	*line;
	int		fd;
	t_count	*item;
	//size_t	line_len;

	item = malloc(sizeof(t_count));
	item->collectible = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	//line_len = ft_strlen(line);
	while (line != NULL)
	{
		line_checker(line, item);
		line = get_next_line(fd);
		// if (line_len != ft_strlen(line))
		// {
		// 	ft_putstr_fd("Error\n", 2);
		// 	ft_putstr_fd("Map isn't rectangle\n", 2);
		// 	exit(1);
		// }
	}
	if (item->collectible <= 0 || item->exit != 1 || item->start != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map not valid\n", 2);
		exit(1);
	}
	return (0);
}

void	line_checker(char *line, t_count *item)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			item->collectible++;
		if (line[i] == 'E')
			item->exit++;
		if (line[i] == 'P')
			item->start++;
		i++;
	}
}
