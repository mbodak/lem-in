/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:36:06 by mbodak            #+#    #+#             */
/*   Updated: 2017/05/15 12:36:08 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_data_str(t_into *hill)
{
	int	i;

	if (hill->data == NULL)
		return ;
	i = 0;
	while (hill->data && hill->data[i])
	{
		free(hill->data[i]);
		i++;
	}
	free(hill->data);
	hill->data = NULL;
}

static void		free_rooms(t_into *hill)
{
	int	i;

	if (hill->rooms == NULL)
		return ;
	i = 0;
	while (hill->rooms && hill->rooms[i])
	{
		free(hill->rooms[i]->name);
		free(hill->rooms[i]);
		i++;
	}
	free(hill->rooms);
	hill->rooms = NULL;
}

static void		free_links(t_into *hill)
{
	int	i;

	if (hill->links == NULL)
		return ;
	i = 0;
	while (hill->links && hill->links[i])
	{
		free(hill->links[i]);
		i++;
	}
	free(hill->links);
	hill->links = NULL;
}

static void		free_matrix(t_into *hill)
{
	int	i;

	if (hill->matrix == NULL)
		return ;
	i = 0;
	while (i < hill->m_len)
		free(hill->matrix[i++]);
	free(hill->matrix);
	hill->matrix = NULL;
}

void			free_data(t_into *hill)
{
	free_data_str(hill);
	free_rooms(hill);
	free_links(hill);
	free_matrix(hill);
}
