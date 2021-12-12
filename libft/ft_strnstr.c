/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:53:35 by mbarut            #+#    #+#             */
/*   Updated: 2021/05/26 17:38:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t size)
{
	size_t	n;

	n = 0;
	if (!s || size == 0)
		return (n);
	while (s[n] != '\0' && size--)
	{
		n++;
	}
	return (n);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;
	size_t	little_len_org;

	little_len_org = ft_strlen(little);
	little_len = ft_strnlen(little, len);
	if (ft_strlen(big) < ft_strlen(little) || (little_len_org != 0 && len == 0))
		return (NULL);
	if (little_len == 0 || (!little && len == 0))
		return ((char *)big);
	i = 0;
	while (i <= (int)(len - little_len))
	{
		if ((big[0] == little[0]) && (ft_strncmp(big, little, little_len) == 0))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
