/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:28:58 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/24 13:29:01 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*read_line(int fd)
{
	ssize_t		size;
	char		buffer[BUFF_SIZE + 1];

	if ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[size] = '\0';
		return (ft_strdup(buffer));
	}
	else
		return (NULL);
}

char		*check_str(char **remain)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (*remain == NULL)
		return (NULL);
	if (!(ft_strchr((*remain), '\n')))
		return (NULL);
	len = 0;
	while ((*remain)[len] != '\n')
		len++;
	str = ft_strsub((*remain), 0, len);
	tmp = ft_strsub((*remain), (int)len + 1, ft_strlen(*remain) - len - 1);
	if (tmp[0] == '\0')
		tmp = NULL;
	free((*remain));
	*remain = tmp;
	return (str);
}

char		*get_line(int fd, t_line *begin_list)
{
	char	*line;
	char	*str;

	while (begin_list && begin_list->fd != fd)
		begin_list = begin_list->next;
	while ((line = check_str(&(begin_list)->remain)) == NULL)
	{
		str = read_line(fd);
		if (!str)
		{
			line = begin_list->remain;
			begin_list->remain = NULL;
			return (line);
		}
		if (begin_list->remain == NULL)
			begin_list->remain = str;
		else
			begin_list->remain = ft_joinfree(begin_list->remain, str, BOTH);
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*begin_list;

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (!begin_list)
		begin_list = create_elem(fd);
	if (!(check_fd(fd, begin_list)))
		elem_add(fd, &begin_list);
	if (!(*line = get_line(fd, begin_list)))
		return (0);
	return (1);
}
