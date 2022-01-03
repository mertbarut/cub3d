/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_checkspaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:56:20 by dmylonas          #+#    #+#             */
/*   Updated: 2022/01/03 14:27:20 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_checkspaces(t_cubfile *f, t_data *cub)
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
					cubfile_error(cub, 5);
				if ((i -1 >= 0) && (f->map[i - 1][j] == 0))
					cubfile_error(cub, 5);
				if ((j + 1 < f->max_rows) && (f->map[i][j + 1] == 0))
					cubfile_error(cub, 5);
				if ((j - 1 >= 0) && (f->map[i][j - 1] == 0))
					cubfile_error(cub, 5);
			}
			j++;
		}
		i++;
	}
}

void	cubfile_check_zeros(t_cubfile *f, t_data *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->n_rows)
	{
		j = 0;
		while (j < f->max_rows)
		{
			if (f->map[i][j] == 0)
			{
				if ((i + 1 < f->n_rows) && (f->map[i + 1][j] == 3))
					cubfile_error(cub, 5);
				if ((i -1 >= 0) && (f->map[i - 1][j] == 3))
					cubfile_error(cub, 5);
				if ((j + 1 < f->max_rows) && (f->map[i][j + 1] == 3))
					cubfile_error(cub, 5);
				if ((j - 1 >= 0) && (f->map[i][j - 1] == 3))
					cubfile_error(cub, 5);
			}
			j++;
		}
		i++;
	}
}
