/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.1wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:15:49 by mbarut            #+#    #+#             */
/*   Updated: 2021/07/28 15:52:55 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

static int	check_new_line(char **line, char c_buff, int is_map)
{
	if (c_buff == '\n' && is_map == 1)
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = '5';
		return (0);
	}
	return (1);
}

int	get_next_line(const int fd, char **line, int is_map)
{
	int			ret;
	static char	*s[1080 * 3 / 2];
	char		buff[42];
	char		*tmp;

	ret = read(fd, buff, 1);
	if (check_new_line(line, buff[0], is_map) == 0)
		return (1);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		ret = read(fd, buff, 1);
	}
	return (output(s, line, ret, fd));
}
