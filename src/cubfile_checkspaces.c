/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_checkspaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:56:20 by dmylonas          #+#    #+#             */
/*   Updated: 2021/12/31 18:12:55 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_checkspaces(t_cubfile *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->n_rows)
	{
		j = 0;
		while (j < f->max_rows)
		{
			if (f->map[i][j] == 2)
			{
				if ((i + 1 < f->n_rows) && (f->map[i + 1][j] == 0))
					cubfile_error(5);
				if ((i -1 >= 0) && (f->map[i - 1][j] == 0))
					cubfile_error(5);
				if ((j + 1 < f->max_rows) && (f->map[i][j + 1] == 0))
					cubfile_error(5);
				if ((j - 1 >= 0) && (f->map[i][j - 1] == 0))
					cubfile_error(5);
			}
			j++;
		}
		i++;
	}
}
