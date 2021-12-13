/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_column_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:42:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 23:25:56 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
/*
void	cub_format_col(t_cubfile *gnl, int col, int j)
{
	int	i;

	i = gnl->row_count - 1;
	if (j != col)
	{
		ft_putstr_fd("Error: Columns have different sizes in .cub file \n", 2);
		while (i >= 0)
			ft_split_free(gnl->points[i--], j);
		exit(EXIT_FAILURE);
	}
}

int	cubfile_column_count_checker(t_cubfile *cubfile)
{
	int	i;

	i = 0;
	while (cubfile->row_count != 0 && cubfile->points[0][i] != NULL)
		i++;
	return (i);
}

int	cubfile_column_count(t_cubfile *cubfile)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	j = 0;
	col = cubfile_column_count_checker(cubfile);
	while (i < cubfile->row_count)
	{
		j = 0;
		while (cubfile->points[i][j] != NULL)
			j++;
		cub_format_col(cubfile, col, j);
		i++;
	}
	return (j);
}
*/