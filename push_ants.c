/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:11:56 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/29 14:11:58 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_ants(t_into *hill)
{
	int 	i;
	int 	j;
	int 	ant_num;

	hill->ants_move = (t_ant **)malloc(sizeof(t_ant) * (hill->ants + 1));
	chose_ways(hill);
	i = 0;
	ant_num = 1;
	while (i < hill->ants)
	{
		j = 0;
		while (hill->ways[j])
		{
			hill->ants_move[i] = (t_ant *)malloc(sizeof(t_ant));
			hill->ants_move[i]->room = hill->start;
			hill->ants_move[i]->ant_num = ant_num++;
			hill->ants_move[i]->way_id = j;
			j++;
		}
		i++;
	}
	hill->ants_move[i] = NULL;
}

int 	push_ants(t_into *hill)
{
	int		i;
	int 	j;

	add_ants(hill);
	i = 0;
	j = 0;
	while (hill->ants_move && hill->ants_move[i])
	{
		if (hill->ants_move[i]->room == hill->start)

		i++;
	}
}

