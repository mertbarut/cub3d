/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:46 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/03 20:21:00 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define SCREEN_H 480
# define SCREEN_W 640

# define TEX_H 64
# define TEX_W 64

# define PLAYER_FOV	66
# define PLAYER_ROTATE_SPEED 0.05
# define PLAYER_MOVE_SPEED 0.05

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define MIN_PWD 0.01

# define TRANSPARENT 0x489848

# define BOOT_TIMER	2022
# define BOOT_TIMER_MODIFIER 2.2

# define LEFT -1
# define RIGHT 1
# define DOWN -1
# define UP 1

# define KEY_RIGHT_ARROW 0xFF51
# define KEY_LEFT_ARROW 0xFF53
# define KEY_ESCAPE 0xFF1B

enum e_direction
{
	east,
	north,
	west,
	south
};

typedef struct s_line {
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e2;
	int		err;
}				t_line;

typedef struct s_pixel {
	double	x;
	double	y;
	int		color;
}				t_pixel;

typedef struct s_vector {
	double	x;
	double	y;
}				t_vector;

typedef struct s_player {
	t_vector	pos;
	t_vector	dir;
	t_vector	pln;
	double		speed_move;
	double		speed_rotate;
}				t_player;

typedef struct s_texture
{
	int			count;
	int			height;
	int			width;
	int			color_xor;
	int			color_x;
	int			color_y;
	int			color_xy;
	int			container[4][TEX_W * TEX_H];
	double		pos;
	double		step;
}				t_texture;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	int		i;
}				t_img;

typedef struct s_cubfile {
	int			**map;
	char		*line;
	char		*path[4];
	int			rgb_color_floor[3];
	int			rgb_color_ceiling[3];
	int			max_rows;
	int			n_rows;
	char		flag_player_direction;
}				t_cubfile;

typedef struct s_data {
	t_cubfile	*file;		
	void		*mlx;
	void		*win;
	t_img		*frame;
	t_img		*img_side_n;
	t_img		*img_side_s;
	t_img		*img_side_w;
	t_img		*img_side_e;
	t_img		*img_coffee;
	t_img		*logo;
	t_img		*menu;
	int			height;
	int			width;
	t_player	*player;
	t_texture	*texture;
	int			buffer[SCREEN_H][SCREEN_W];
	int			start;
	int			boot;
	int			color_floor;
	int			color_ceiling;
}				t_data;

typedef struct s_ray {
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			tile_x;
	int			tile_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			color;
	t_pixel		draw_start;
	t_pixel		draw_end;
	double		pwd;
	int			texture_i;
	double		wall_x;
	int			texture_x;
	int			texture_y;
	int			line_height;	
}				t_ray;

/* PARSING */
void	cubfile_handle(t_data *cub, const char *path);
void	cubfile_error(t_data *cub, int signal);
void	free_double(void **to_free);
void	cubfile_parsecolor(t_cubfile *f, t_data *cub, int rgb[3]);
void	cubfile_setcolor(t_data *cub);
void	cubfile_configure(t_cubfile *f, t_data *cub);
void	cubfile_fillmap(t_data *cub, int fd);
void	cubfile_checkmap(t_data *cub);
void	cubfile_checkspaces(t_cubfile *f, t_data *cub);
void	cubfile_check_zeros(t_cubfile *f, t_data *cub);

/* RAYCASTING & RENDERING */
void	raycasting_calc(t_ray *ray, t_player *player);
void	raycasting_send(t_data *cub, t_ray *ray);
void	raycasting_setpixel(int x, t_ray *ray, t_player *player);
void	raycasting_texture_getpos(t_texture *t, t_ray *ray, t_player *player);
void	raycasting_texture_setcol(int x, t_texture *t, t_ray *ray, t_data *cub);
void	draw_buffer(t_data *cub);

/* PLAYER */
void	player_init(t_data *cub, t_player *player);
void	player_move_forward(t_data *cub);
void	player_move_backward(t_data *cub);
void	player_move_right(t_data *cub);
void	player_move_left(t_data *cub);
void	player_rotate_right(t_data *cub);
void	player_rotate_left(t_data *cub);

/* TEXTURES */
void	texture_init(t_data *cub, t_texture *t);

/* CUB3D */
void	cub_args(int argc, char **argv);
void	cub_init(t_data *cub);
int		cub_boot(t_data *cub);
int		cub_render(t_data *cub);
void	cub_draw(t_data *cub, t_pixel *p0, t_pixel *p1, int color);
int		cub_key(int key, t_data *cub);
void	cub_exit(t_data *cub, char *str, int signal);
int		cub_pressx(t_data *cub);

/* IMG */
void	img_init(t_data *cub);

#endif
