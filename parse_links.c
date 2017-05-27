/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:11:57 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/25 16:11:59 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			cmp_n(t_into *hill, char *string)
{
	int		index;
	int		yes;

	yes = 0;
	index = 0;
	while (hill->rooms && hill->rooms[index])
	{
		if (ft_strequ(string, hill->rooms[index]->name))
		{
			yes = 1;
			break ;
		}
		index++;
	}
	if (!yes)
		return (-1);
	return (index);
}

int			add_link(t_into *hill, char **arr)
{
	t_link	*link;
	t_link	**links;
	int		len;

	link = (t_link *)malloc(sizeof(t_link));
	link->name1 = cmp_n(hill, arr[0]);
	link->name2 = cmp_n(hill, arr[1]);
	len = 0;
	while (hill->links && hill->links[len])
		len++;
	links = (t_link **)malloc(sizeof(t_link *) * (len + 2));
	len = 0;
	while (hill->links && hill->links[len])
	{
		links[len] = hill->links[len];
		len++;
	}
	links[len] = link;
	links[len + 1] = NULL;
	if (hill->links)
		free(hill->links);
	hill->links = links;
	return (len);
}

int			parse_links(t_into *hill, int i)
{
	char	**arr;
	int		len;

	arr = ft_strsplit(hill->data[i], '-');
	len = 0;
	while (arr[len])
		len++;
	if ((len != 2 || cmp_n(hill, arr[0]) == -1)
		|| (cmp_n(hill, arr[1]) == -1))
		return (0);
	add_link(hill, arr);
	return (1);
}
