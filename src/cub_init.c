/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:51:03 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/13 01:46:47 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_init(t_data *cub, t_player *player)
{
	cub->height = SCREEN_H;
	cub->width = SCREEN_W;
	cub->rows = 24;
	cub->cols = 24;
	cub->player = player;
}
