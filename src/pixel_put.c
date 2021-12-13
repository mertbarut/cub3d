/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:10:49 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 18:45:56 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
/* 
// This function is for putting pixels to an image rather than directly the window  
void	pixel_put(t_data *cub, int x, int y, int color)
{
	char	*dst;

	//if (y + fdf->center_y > fdf->height || y + fdf->center_y < 0
	//	|| x + fdf->center_x > fdf->width || x + fdf->center_x < 0)
	//	return ;
	dst = cub->addr + ((y) * cub->len + (x) * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}
*/