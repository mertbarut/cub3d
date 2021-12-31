/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:33:52 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:52:55 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_img	*img_newframe(t_data *cub)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	img->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size, &img->endian);
	img->width = cub->width;
	img->height = cub->height;
	return (img);
}

static t_img	*img_xpm(t_data *cub, char *path)
{
	t_img	*img;
	int		height;
	int		width;

	img = malloc(sizeof(*img));
	img->img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (!(img->img))
		cubfile_error(6);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size, &img->endian);
	img->width = width;
	img->height = height;
	img->i = 0;
	return (img);
}

void	img_init(t_data *cub)
{
	cub->frame = img_newframe(cub);
	cub->logo = img_xpm(cub, "img/cub_42.xpm");
	cub->menu = img_xpm(cub, "img/cub_menu.xpm");
	cub->img_side_s = img_xpm(cub, cub->file->path[SOUTH]);
	cub->img_side_w = img_xpm(cub, cub->file->path[WEST]);
	cub->img_side_n = img_xpm(cub, cub->file->path[NORTH]);
	cub->img_side_e = img_xpm(cub, cub->file->path[EAST]);
	cub->img_coffee = img_xpm(cub, "textures/coffee256.xpm");
}
