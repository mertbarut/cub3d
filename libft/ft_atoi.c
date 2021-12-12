/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:42:01 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/26 18:03:10 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\n') || (c == '\t')
		|| (c == '\r') || (c == '\v') || (c == '\f'));
}

long	ft_atoi(const char *nptr)
{
	long	n;
	int		neg;

	n = 0;
	neg = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		neg = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		n = 10 * n - (*nptr++ - '0');
	if (neg == 1)
		return (n);
	else
		return (-n);
}
