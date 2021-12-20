/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:33:52 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 12:31:57 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_img	*img_newframe(t_data *cub)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	img->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size, &img->endian);
	img->width = cub->width;
	img->height = cub->height;
	return (img);
}

t_img	*img_xpm(t_data *cub, char *path)
{
	t_img	*img;
	int		height;
	int		width;

	img = malloc(sizeof(*img));
	img->img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

void	img_init(t_data *cub)
{
	cub->frame = img_newframe(cub);
	cub->img2 = img_xpm(cub, "../cub3d/textures/player64.xpm");
	cub->logo = img_xpm(cub, "../cub3d/img/cub_42.xpm");
	cub->menu = img_xpm(cub, "../cub3d/img/cub_menu.xpm");
}
