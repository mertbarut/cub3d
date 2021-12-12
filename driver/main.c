/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:14:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:56:30 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fdf.h"

int	main(int argc, char *argv[])
{
	t_data		fdf;
	t_gnl		gnl;
	t_pixel		**pixels;

	fdf_read(&gnl, argc, argv);
	map_init(&gnl, &fdf.map);
	pixels = ft_calloc(fdf.map.n + 1, sizeof(struct s_pixel *));
	fdf_map(&gnl, pixels, &fdf.map);
	fdf.mlx = mlx_init();
	fdf_init(&fdf);
	fdf.win = mlx_new_window(fdf.mlx, fdf.width, fdf.height, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, fdf.width, fdf.height);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.len, &fdf.endian);
	mlx_hook(fdf.win, 2, 1L << 0, fdf_close, &fdf);
	mlx_key_hook(fdf.win, map_move, &fdf);
	mlx_loop_hook(fdf.mlx, map_render, &fdf);
	mlx_loop(fdf.mlx);
}
