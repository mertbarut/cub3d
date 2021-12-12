/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_column_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:42:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:14:57 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_format_col(t_gnl *gnl, int col, int j)
{
	int	i;

	i = gnl->row_count - 1;
	if (j != col)
	{
		ft_putstr_fd("Error: Columns have different sizes in .fdf file \n", 2);
		while (i >= 0)
			ft_split_free(gnl->points[i--], j);
		exit(0);
	}
}

int	gnl_column_count_checker(t_gnl *gnl)
{
	int	i;

	i = 0;
	while (gnl->row_count != 0 && gnl->points[0][i] != NULL)
		i++;
	return (i);
}

int	gnl_column_count(t_gnl	*gnl)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	j = 0;
	col = gnl_column_count_checker(gnl);
	while (i < gnl->row_count)
	{
		j = 0;
		while (gnl->points[i][j] != NULL)
			j++;
		fdf_format_col(gnl, col, j);
		i++;
	}
	return (j);
}
