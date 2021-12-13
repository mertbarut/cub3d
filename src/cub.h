/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 02:05:12 by mbarut           ###   ########.fr       */
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
# include <mlx.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define SCREEN_H 480
# define SCREEN_W 640

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
}				t_player;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	t_player	*player;
	int			cols;
	int			rows;
	int			*map;
}				t_data;

typedef struct s_cubfile {
	char	*line[1080];
	char	**points[1000000];
	int		fd;
	int		i;
	size_t	row_count;
}				t_cubfile;

/* PIXEL */
void	pixel_put(t_data *data, int x, int y, int color);

/* PLAYER */
void	player_init(t_player *player, double fov, t_cubfile *cubfile);
int		player_move(int key, t_data *cub);

/* CUB3D */
void	cub_init(t_data *cub, t_player *player);
void	cub_read(t_cubfile *cubfile, int argc, char *argv[]);
int		cub_close(int keycode, t_data *cub);
int		cub_render(t_data *cub);
void	cub_draw(t_data *cub, t_pixel *p0, t_pixel *p1);
int		cub_file(t_cubfile *cubfile);

#endif
