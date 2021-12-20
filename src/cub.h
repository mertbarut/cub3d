/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 13:35:31 by mbarut           ###   ########.fr       */
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
# define TEX_N 8

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
	int			container[8][TEX_W * TEX_H];
	double		pos;
	double		step;
}				t_texture;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		*frame;
	t_img		*img2;
	t_img		*logo;
	t_img		*menu;
	int			height;
	int			width;
	t_player	*player;
	t_texture	*texture;
	int			buffer[SCREEN_H][SCREEN_W];
	int			start;
	int			boot;
	int			bg_color_floor;
	int			bg_color_ceiling;
}				t_data;

typedef struct s_ray {
	double		cam_x;
	t_vector	dir;
	t_vector	side_dist;				// length of ray from current position to next x or y-side
	t_vector	delta_dist;				// length of ray from one x or y-side to next x or y-side
	int			tile_x;					// position of tile the player is in
	int			tile_y;					// ditto
	int			step_x;					// what direction to step in x or y-direction (either +1 or -1)
	int			step_y;					// ditto
	int			hit;
	int			side;
	int			color;
	t_pixel		draw_start;
	t_pixel		draw_end;
	double		perp_wall_dist;
	int			texture_i;
	double		wall_x;
	int			texture_x;
	int			texture_y;
	int			line_height;	
}				t_ray;

typedef struct s_cubfile {
	char	*line[1080];
	char	**points[1000000];
	int		fd;
	int		i;
	size_t	row_count;
}				t_cubfile;

/* RENDERING */
void	pixel_put(t_data *data, int x, int y, int color);
void	vertical_line(t_data *cub, int x, int y1, int y2, int color);
void	draw_buffer(t_data *cub);

/* PLAYER */
void	player_init(t_player *player, double fov, t_cubfile *cubfile);
void	player_move_forward(t_data *cub);
void	player_move_backward(t_data *cub);
void	player_move_right(t_data *cub);
void	player_move_left(t_data *cub);
void	player_rotate_right(t_data *cub);
void	player_rotate_left(t_data *cub);

/* TEXTURES */
void	texture_init(t_data *cub, t_texture *t);

/* CUB3D */
void	cub_init(t_data *cub, t_player *player);
void	cub_read(t_cubfile *cubfile, int argc, char *argv[]);
int		cub_render(t_data *cub);
void	cub_draw(t_data *cub, t_pixel *p0, t_pixel *p1, int color);
int		cub_file(t_cubfile *cubfile);
int		cub_key(int key, t_data *cub);
void	cub_exit(t_data *cub);

/* IMG */
void	img_init(t_data *cub);

#endif
