/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:09:20 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/03 20:20:43 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_error(t_data *cub, int signal)
{
	printf("\x1B[31mError\n");
	if (signal == -1)
		printf("Setting file misconfigured\n");
	else if (signal == 0)
		printf("Setting file couldn't open\n");
	else if (signal == 1)
		printf("A texture was given more than once\n");
	else if (signal == 2)
		printf("Color for ceiling or floor misconfig\n");
	else if (signal == 3)
		printf("Color out of range\n");
	else if (signal == 4)
		printf("Map can only contain 0, 1 and ONLY one NSWE\n");
	else if (signal == 5)
		printf("Map borders should be 1\n");
	else if (signal == 6)
		printf("Invalid wall texture path\n");
	else if (signal == 7)
		printf("Map should contain N or W or S or E\n");
	else if (signal == 9)
		printf("Empty line in the map\n");
	printf("\x1B[0m");
	cub_exit(cub, NULL, signal);
}
