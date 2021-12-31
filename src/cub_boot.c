/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_boot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:05:54 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:26:24 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_boot(t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < BOOT_TIMER)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->logo->img, 0, 0);
		if (i > BOOT_TIMER / BOOT_TIMER_MODIFIER)
		{
			j = 0;
			while (j < SCREEN_W * SCREEN_H)
			{
				if (cub->logo->data[j] > 0)
					cub->logo->data[j] = 0;
				j++;
			}
		}
		if (i == BOOT_TIMER - 1 && ++cub->boot)
			return (1);
		i++;
	}
	return (0);
}
