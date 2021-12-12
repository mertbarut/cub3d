/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:12:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:56:57 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_reset(t_data *fdf)
{
	int	*image;
	int	i;
	int	resolution;

	resolution = fdf->width * fdf->height;
	ft_bzero(fdf->addr, resolution * (fdf->bpp / 8));
	image = (int *)(fdf->addr);
	i = 0;
	while (i < resolution)
	{
		image[i] = 0;
		i++;
	}
}
