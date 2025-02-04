/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:32:45 by pribolzi          #+#    #+#             */
/*   Updated: 2025/02/04 19:07:03 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 2170
# define HEIGHT 1225
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define FRAMERATE 1000

typedef struct s_props
{
	char	*wall;
	char	*floor;
	char	*character;
	char	*item;
	char	*exit[6];
	char	*character_e;
	char	*enemy;
	char	*enemy_c;
	void	*img_enemy_c;
	void	*img_enemy;
	void	*img_exit[6];
	void	*img_item;
	void	*img_wall;
	void	*img_character;
	void	*img_floor;
	void	*img_character_e;
	int		height;
	int		width;
}			t_props;

typedef struct s_count
{
	int		collectible;
	int		exit;
	int		start;
}			t_count;

typedef struct s_hero
{
	int		move;
	int		life;
}			t_hero;

typedef struct s_enemy
{
	int		p_x;
	int		p_y;
	int		is;
}			t_enemy;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit_y;
	int		exit_x;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	t_props	*props;
	t_map	*map;
	t_count	*item;
	t_hero	*player;
	t_enemy	*npc;
}			t_vars;

/*Handling key*/
int			handle_key(int keycode, t_vars *data);

/*PARSING*/
int			check_map(char *filename, t_vars *data);
void		line_checker(char *line, t_vars *data);
int			valid_file(char *filename);
int			check_flood(char **map, t_vars *data);
char		**flood_fill(char **map, int y, int x);
int 		get_pos_y(t_vars *data, char c);
int 		get_pos_x(t_vars *data, char c);

/*ANIMATION*/
int			base_animation(t_vars *data);

/*FREE*/
int			destroy(t_vars *data);

/*MAP*/
void		render_map(t_vars *data, t_map *map);
int			check_grid(t_vars *data, int y, int x);

/*INIT*/
void		init_map(char *filename, t_map *map);
void		render_map(t_vars *data, t_map *map);
int			ft_malloc(t_vars *data);
void		init_animation(t_vars *data);
void		init_enemy(t_vars *data);
void		init_texture(t_vars *data);

/*IMAGE*/
void		put_image(t_vars *data, int type, int y, int x);

/*UTILS*/
int			check_collision(t_vars *data, int sense);
void		get_height(t_map *map, int fd);
void		show_movement(t_vars *data);

#endif