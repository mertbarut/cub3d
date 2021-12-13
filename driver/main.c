/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:14:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 01:55:19 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/cub.h"
#include <mlx.h>

int worldMap[24][24] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	verLine(t_data *cub, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}

int	main(int argc, char *argv[])
{
	t_data		cub;
	t_player	player;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, SCREEN_W, SCREEN_H, "cub3d");
	cub.img = mlx_new_image(cub.mlx, SCREEN_W, SCREEN_H);
	cub.addr = mlx_get_data_addr(cub.img, &cub.bpp, &cub.len, &cub.endian);
	mlx_hook(cub.win, 2, 1L << 0, cub_close, &cub); // ESC -> exit()
	mlx_key_hook(cub.win, player_move, &cub); // WASD
	//mlx_expose_hook(cub.win, player_move, &cub);
	//mlx_loop_hook(cub.mlx, map_render, &cub);

	cub_init(&cub, &player);
	player_init(&player, 66, NULL);

	/* raycasting */

	int	x;
	x = 0;
	while (x < 24)
	{
		double cam_x = 2 * x / (double)SCREEN_W - 1;
		double ray_dir_x = player.dir.x + player.pln.x * cam_x;
		double ray_dir_y = player.dir.y + player.pln.y * cam_x;

		// which box of the map we're in
    	int map_x = (int)player.pos.x;
    	int map_y = (int)player.pos.y;

    	// length of ray from current position to next x or y-side
    	double side_dist_x;
    	double side_dist_y;

    	//length of ray from one x or y-side to next x or y-side
		double delta_dist_x;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);

		double delta_dist_y;
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);

    	//what direction to step in x or y-direction (either +1 or -1)
    	int step_x;
    	int step_y;

    	int hit; //was there a wall hit?
		hit = 0;
    	int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - player.pos.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player.pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - player.pos.y) * delta_dist_y;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[map_x][map_y] > 0)
				hit = 1;
		}
		
		double perp_wall_dist;

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    	if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
    	else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		//Calculate height of line to draw on screen
		int line_height;
		line_height = (int)(SCREEN_H / perp_wall_dist);
		
		//calculate lowest and highest pixel to fill in current stripe
		int draw_start;
		draw_start = -line_height / 2 + SCREEN_H / 2;
		if (draw_start < 0)
			draw_start = 0;

		int draw_end;
		draw_end = line_height / 2 + SCREEN_H / 2;
		if (draw_end >= SCREEN_H)
			draw_end = SCREEN_H - 1;

		//choose wall color
    	int color;

		if (worldMap[map_x][map_y] == 1)
			color = 0xde3163;
		else if (worldMap[map_x][map_y] == 2)
			color = 0x9fe2bf;
		else if (worldMap[map_x][map_y] == 3)
			color = 0x6495ed;
		else if (worldMap[map_x][map_y] == 4)
			color = 0xffffff;
		else
			color = 0xdfff00;

    	//give x and y sides different brightness
    	if (side == 1)
			color = color / 2;

		t_pixel p0;
		t_pixel p1;

		p0.x = x;
		p1.x = x;

		p0.y = draw_start;
		p1.y = draw_end;

    	//draw the pixels of the stripe as a vertical line
    	cub_draw(&cub, &p0, &p1);
		
		x++;
	}
	
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);
	mlx_loop(cub.mlx); // must stay at end of the scope

	//fdf_read(&gnl, argc, argv); // open and read from a .cub file 
	//map_init(&gnl, &fdf.map);
	//pixels = ft_calloc(fdf.map.n + 1, sizeof(struct s_pixel *));
	//fdf_map(&gnl, pixels, &fdf.map);
	//fdf.mlx = mlx_init();
	//fdf_init(&fdf);
	//fdf.win = mlx_new_window(fdf.mlx, fdf.width, fdf.height, "cub3d");
	//fdf.img = mlx_new_image(fdf.mlx, fdf.width, fdf.height);
	//fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.len, &fdf.endian);
	//mlx_hook(fdf.win, 2, 1L << 0, fdf_close, &fdf);
	//mlx_key_hook(fdf.win, map_move, &fdf);
	//mlx_loop_hook(fdf.mlx, map_render, &fdf);
	//mlx_loop(fdf.mlx);
}
