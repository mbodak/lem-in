/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:15:31 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/24 18:15:34 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_ants(t_into *hill, int i)
{
	if (!is_digit(hill->data[i]))
		return (0);
	hill->ants = ft_atoi(hill->data[i]);
	if (hill->ants <= 0)
		return (0);
	return (1);
}

int		add_room(t_into *hill, char **arr)
{
	t_room		*room;
	t_room		**rooms;
	int			len;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = arr[0];
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	len = 0;
	while (hill->rooms && hill->rooms[len])
		len++;
	rooms = (t_room **)malloc(sizeof(t_room *) * (len + 2));
	len = 0;
	while (hill->rooms && hill->rooms[len])
	{
		rooms[len] = hill->rooms[len];
		len++;
	}
	rooms[len] = room;
	rooms[len + 1] = NULL;
	if (hill->rooms)
		free(hill->rooms);
	hill->rooms = rooms;
	return (len);
}

int		parse_rooms(t_into *hill, int i, t_command command, int len)
{
	char	**a;

	a = ft_strsplit(hill->data[i], ' ');
	while (a[len])
		len++;
	if (len != 3 || a[0][0] == '#' || a[0][0] == 'L' || cmp_n(hill, a[0]) != -1)
		return (ft_free_arr(a, 0));
	if (!is_digit(a[1]) || !is_digit(a[2]))
		return (ft_free_arr(a, 0));
	len = add_room(hill, a);
	ft_free_arr(a, 1);
	if (command == START)
	{
		if (hill->start != -1)
			return (0);
		hill->start = len;
	}
	else if (command == END)
	{
		if (hill->end != -1)
			return (0);
		hill->end = len;
	}
	return (1);
}

int		parser(t_into *hill, int i)
{
	t_command	command;

	if (hill->data[0] == NULL)
		return (0);
	while (is_comment(hill->data[i]))
		i++;
	if (!parse_ants(hill, i))
		return (0);
	i++;
	command = is_command(hill->data[i]);
	if (command)
		i++;
	while ((hill->data[i])
			&& (parse_rooms(hill, i, command, 0) || is_comment(hill->data[i])))
	{
		i++;
		if (hill->data[i] && (command = is_command(hill->data[i])))
			i++;
	}
	if (command)
		return (0);
	while (hill->data[i] && (parse_links(hill, i) || is_comment(hill->data[i])))
		i++;
	return (i);
}
