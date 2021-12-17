/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:33:52 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/17 23:35:40 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	img_init(t_data *cub, t_img	*img)
{
	cub->img = img;
	img->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size, &img->endian);
}
