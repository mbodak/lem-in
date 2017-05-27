/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:12:19 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/25 19:12:22 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_matrix(t_into *hill)
{
	int		i;
	int		j;

	while (hill->rooms && hill->rooms[hill->m_len])
		hill->m_len++;
	hill->matrix = (int **)malloc(sizeof(int *) * hill->m_len);
	i = 0;
	while (i < hill->m_len)
	{
		hill->matrix[i] = (int *)malloc(sizeof(int) * hill->m_len);
		j = 0;
		while (j < hill->m_len)
		{
			hill->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		fill_matrix(t_into *hill)
{
	int		i;

	create_matrix(hill);
	i = 0;
	while (hill->links && hill->links[i])
	{
		hill->matrix[hill->links[i]->name1][hill->links[i]->name2] = 1;
		hill->matrix[hill->links[i]->name2][hill->links[i]->name1] = 1;
		i++;
	}
}
