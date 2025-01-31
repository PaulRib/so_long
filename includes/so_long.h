/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:32:45 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/31 20:21:40 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

#define WIDTH 2880
#define HEIGHT 1620
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

typedef struct s_props {
	char	*wall;
	char	*floor;
	char	*character;
	char 	*item;
	char 	*exit;
	char 	*character_e;
	void 	*img_exit;
	void 	*img_item;
	void	*img_wall;
	void 	*img_character;
	void 	*img_floor;
	void 	*img_character_e;
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
	t_props *props;
	t_map 	*map;
	t_count	*item;
}				t_vars;



int		destroy(t_vars	*data);
void 	init_texture(t_vars *data);
void 	ft_free_all(t_vars *data);
void 	free_images(t_vars *data);
int 	get_height(t_map *map, int fd);

/*Handling key*/
void 	handle_movement(int keycode, t_vars *data);
int		handle_key(int keycode, t_vars *data);
void 	movement_right(t_vars *data);
void 	movement_left(t_vars *data);
void 	movement_down(t_vars *data);
void 	movement_up(t_vars *data);
void 	put_image(t_vars *data, int type, int y, int x);
int 	check_grid(t_vars *data, int y, int x);

/*CHECK MAP*/
int		check_map(char *filename, t_vars *data);
int		check_props(char *filename, t_vars *data);
void	line_checker(char *line, t_vars *data);
int 	check_form(t_vars *data);
int 	check_close(t_vars *data);

/*INIT*/
void 	init_map(char *filename, t_map *map);
void 	render_map(t_vars *data, t_map *map);
int		valid_file(char *filename);
int		ft_malloc(t_vars *data);

#endif