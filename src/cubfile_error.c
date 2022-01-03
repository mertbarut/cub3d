/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:09:20 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/03 14:27:41 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_error(t_data *cub, int signal)
{
	printf("Error\n");
	printf("%d\n", signal);
	cub_exit(cub, NULL, 0);
	exit (signal);
}
