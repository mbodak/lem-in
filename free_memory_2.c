/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 20:24:33 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/07 20:24:36 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_tmp_ways(t_into *hill)
{
	int i;

	if (hill->tmp_ways == NULL)
		return ;
	i = 0;
	while (hill->tmp_ways && i < hill->tmp_len)
	{
		if (hill->tmp_ways[i])
		{
			free(hill->tmp_ways[i]->way);
			free(hill->tmp_ways[i]);
		}
		i++;
	}
	free(hill->tmp_ways);
	hill->tmp_ways = NULL;
}

static void		free_var_ways(t_into *hill)
{
	int i;

	if (hill->var_ways == NULL)
		return ;
	i = 0;
	while (hill->var_ways && hill->var_ways[i])
	{
		free(hill->var_ways[i]->indexes);
		free(hill->var_ways[i]);
		i++;
	}
	free(hill->var_ways);
	hill->var_ways = NULL;
}

static void		free_ants_move(t_into *hill)
{
	int i;

	if (hill->ants_move == NULL)
		return ;
	i = 0;
	while (hill->ants_move && hill->ants_move[i])
	{
		free(hill->ants_move[i]);
		i++;
	}
	free(hill->ants_move);
	hill->ants_move = NULL;
}

void			free_memory(t_into *hill)
{
	free(hill->stack);
	hill->stack = NULL;
	free_data(hill);
	free_tmp_ways(hill);
	free_var_ways(hill);
	free_ants_move(hill);
}
