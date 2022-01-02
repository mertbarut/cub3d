/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:14:12 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/02 15:45:33 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub.h"

int	main(int argc, char *argv[])
{
	t_data		cub;
	t_player	player;
	t_texture	texture;
	t_cubfile	file;

	cub.file = &file;
	cub.player = &player;
	cub_args(argc, argv);
	cubfile_handle(&cub, argv[1]);
	player_init(&cub, &player);
	cub_init(&cub);
	img_init(&cub);
	texture_init(&cub, &texture);
	mlx_loop_hook(cub.mlx, cub_render, &cub);
	mlx_hook(cub.win, 17, 1L << 0, cub_pressx, &cub);
	mlx_hook(cub.win, 2, 1L << 0, cub_key, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
