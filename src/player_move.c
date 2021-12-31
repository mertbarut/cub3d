/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:13:45 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 17:52:50 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_move_forward(t_data *cub)
{
	t_player	*p;
	t_cubfile	*f;

	p = cub->player;
	f = cub->file;
	if (!f->map[(int)(p->pos.x + p->dir.x * p->speed_move)][(int)(p->pos.y)])
		p->pos.x += p->dir.x * p->speed_move;
	if (!f->map[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * p->speed_move)])
		p->pos.y += p->dir.y * p->speed_move;
}

void	player_move_backward(t_data *cub)
{
	t_player	*p;
	t_cubfile	*f;

	p = cub->player;
	f = cub->file;
	if (!f->map[(int)(p->pos.x - p->dir.x * p->speed_move)][(int)(p->pos.y)])
		p->pos.x -= p->dir.x * p->speed_move;
	if (!f->map[(int)(p->pos.x)][(int)(p->pos.y - p->dir.y * p->speed_move)])
		p->pos.y -= p->dir.y * p->speed_move;
}

void	player_move_right(t_data *cub)
{
	t_player	*p;
	t_cubfile	*f;

	p = cub->player;
	f = cub->file;
	if (!f->map[(int)(p->pos.x + p->pln.x * p->speed_move)][(int)(p->pos.y)])
		p->pos.x += p->pln.x * p->speed_move;
	if (!f->map[(int)(p->pos.x)][(int)(p->pos.y + p->pln.y * p->speed_move)])
		p->pos.y += p->pln.y * p->speed_move;
}

void	player_move_left(t_data *cub)
{
	t_player	*p;
	t_cubfile	*f;

	p = cub->player;
	f = cub->file;
	if (!f->map[(int)(p->pos.x - p->pln.x * p->speed_move)][(int)(p->pos.y)])
		p->pos.x -= p->pln.x * p->speed_move;
	if (!f->map[(int)(p->pos.x)][(int)(p->pos.y - p->pln.y * p->speed_move)])
		p->pos.y -= p->pln.y * p->speed_move;
}
