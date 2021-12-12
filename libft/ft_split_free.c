/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:54:13 by mbarut            #+#    #+#             */
/*   Updated: 2021/12/12 14:15:41 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_free(char **split, int i)
{
	int	j;

	j = 0;
	while (j <= i && split[j] != 0)
		free(split[j++]);
	free(split);
	return (0);
}
