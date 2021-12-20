/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:13:45 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/20 13:26:09 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

extern	int	map[24][24];

void	player_rotate_right(t_data *cub)
{
	t_player	*p;
	double		tmp_pln_x;
	double		tmp_dir_x;

	p = cub->player;
	tmp_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(-p->speed_rotate) - p->dir.y * sin(-p->speed_rotate);
	p->dir.y = tmp_dir_x * sin(-p->speed_rotate) + p->dir.y * cos(-p->speed_rotate);
	tmp_dir_x = p->pln.x;
	p->pln.x = p->pln.x * cos(-p->speed_rotate) - p->pln.y * sin(-p->speed_rotate);
	p->pln.y = tmp_dir_x * sin(-p->speed_rotate) + p->pln.y * cos(-p->speed_rotate);
}

void	player_rotate_left(t_data *cub)
{
	t_player	*p;
	double		tmp_pln_x;
	double		tmp_dir_x;

	p = cub->player;
	tmp_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(p->speed_rotate) - p->dir.y * sin(p->speed_rotate);
	p->dir.y = tmp_dir_x * sin(p->speed_rotate) + p->dir.y * cos(p->speed_rotate);
	tmp_dir_x = p->pln.x;
	p->pln.x = p->pln.x * cos(p->speed_rotate) - p->pln.y * sin(p->speed_rotate);
	p->pln.y = tmp_dir_x * sin(p->speed_rotate) + p->pln.y * cos(p->speed_rotate);
}
