/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:32:45 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/29 18:32:51 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_props {
	char	*wall;
	char	*floor;
	char	*character;
	char 	*collectible;
	char 	*exit;
	void 	*img_exit;
	void 	*img_coll;
	void	*img_wall;
	void 	*img_character;
	void 	*img_floor;
	int 	height;
	int 	width;
}				t_props;

typedef struct s_count {
	int collectible;
	int	exit;
	int start;
}				t_count;

typedef struct s_map{
	char	**grid;
	int 	width;
	int 	height;
	int 	player_x;
	int 	player_y;
	int 	collectibles;
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	t_props props;
}				t_vars;



int		destroy(t_vars	*data);
int		handle_key(int keycode, t_vars *data);
void 	init_texture(t_vars *data);

/*CHECK MAP*/
int		check_map(char *filename);
int		check_props(char *filename);
void	line_checker(char *line, t_count *map);

/*PARSING*/
t_map 	*init_map(char *filename, t_map *map);
void 	render_map(t_vars *data, t_map *map);

#endif