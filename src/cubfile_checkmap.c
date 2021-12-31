/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:04:14 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/31 18:38:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_checkmap(t_data *cub)
{
	int			i;
	t_cubfile	*f;

	f = cub->file;
	if (f->flag_player_direction == '\0')
		cubfile_error(7);
	i = 0;
	while (i < f->max_rows)
	{
		if ((f->map[0][i] == 0) || (f->map[f->n_rows - 1][i] == 0))
			cubfile_error(5);
		i++;
	}
	i = 0;
	while (i < f->n_rows)
	{
		if ((f->map[i][0] == 0)
		|| (f->map[i][f->max_rows - 1] == 0))
			cubfile_error(5);
		i++;
	}
	cubfile_checkspaces(f);
}
