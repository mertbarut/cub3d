/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:10:39 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
	int		col;
	int		row;
	int		x;
	double	y;
	double	z;
	int		color;
}				t_pixel;

typedef struct s_map {
	t_pixel	**pixels;
	int		i;
	int		unit;
	int		row;
	int		col;
	int		n;
	int		ofs_x;
	int		ofs_y;
	int		ofs_x_mv;
	int		ofs_y_mv;
	int		sens;
	int		tilt_y;
	int		tilt_x;
}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		center_x;
	int		center_y;
	t_map	map;
}				t_data;

typedef struct s_gnl {
	char	*line[1080];
	char	**points[1000000];
	int		fd;
	int		i;
	size_t	row_count;
}				t_gnl;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	pixel_put(t_data *data, int x, int y, int color);
void	fdf_read(t_gnl *gnl, int argc, char *argv[]);
void	fdf_map(t_gnl *gnl, t_pixel **pixels, t_map *map);
t_pixel	*pixel_new(int col, int row, double z, int color);
void	map_init(t_gnl *gnl, t_map *map);
int		gnl_column_count(t_gnl	*gnl);
void	fdf_init(t_data *fdf);
int		map_render(t_data *fdf);
void	map_draw(t_data *fdf, t_map *map);
int		map_move(int key, t_data *fdf);
int		fdf_close(int keycode, t_data *fdf);
void	map_reset(t_data *fdf);
void	pixels_free(t_map *map);
int		ft_split_free(char **split, int i);

#endif
