/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:09:20 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/31 18:13:05 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cubfile_error(int signal)
{
	printf("\x1B[31mError: ");
	if (signal == -1)
		printf("setting file misconfigured\n");
	else if (signal == 0)
		printf("setting file couldn't open\n");
	else if (signal == 1)
		printf("a texture was given more than once\n");
	else if (signal == 2)
		printf("color for ceiling or floor misconfig\n");
	else if (signal == 3)
		printf("color out of range\n");
	else if (signal == 4)
		printf("map can only contain 0, 1 and ONLY one NSWE\n");
	else if (signal == 5)
		printf("map borders should be 1\n");
	else if (signal == 6)
		printf("invalid wall texture path\n");
	else if (signal == 7)
		printf("map should contain N or W or S or E\n");
	exit (signal);
}
