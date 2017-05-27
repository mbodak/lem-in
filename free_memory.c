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

static void		free_data(t_into *hill)
{
	int		i;

	if (hill->data == NULL)
		return ;
	i = 0;
	while (hill->data && hill->data[i])
		free(hill->data[i++]);
	free(hill->data);
	hill->data = NULL;
}

static void		free_rooms_links(t_into *hill)
{
	int		i;

	if (hill->rooms == NULL && hill->links == NULL)
		return ;
	i = 0;
	if (hill->rooms != NULL)
	{
		while (hill->rooms && hill->rooms[i])
			free(hill->rooms[i++]);
		free(hill->rooms);
		hill->rooms = NULL;
	}
	if (hill->links != NULL)
	{
		i = 0;
		while (hill->links && hill->links[i])
			free(hill->links[i++]);
		free(hill->links);
		hill->links = NULL;
	}
}

static void		free_matrix(t_into *hill)
{
	int		i;

	if (hill->matrix == NULL)
		return ;
	i = 0;
	while (i < hill->m_len)
		free(hill->matrix[i++]);
	free(hill->matrix);
	hill->matrix = NULL;
}

void	free_memory(t_into *hill)
{
	free_data(hill);
	free_rooms_links(hill);
	free_matrix(hill);
}
