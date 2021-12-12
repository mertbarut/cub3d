/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:41:10 by mbarut            #+#    #+#             */
/*   Updated: 2021/05/20 18:51:08 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			length;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	length = n;
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2 && length != 0)
	{
		str1++;
		str2++;
		length--;
	}
	if (*str1 == *str2 || length == 0)
		return (0);
	else
		return (*str1 - *str2);
}
