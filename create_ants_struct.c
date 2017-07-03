/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 22:05:00 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/08 22:05:02 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_ants_struct(t_into *hill)
{
	int	i;

	hill->ants_move = (t_ant **)malloc(sizeof(t_ant) * (hill->ants + 1));
	i = 0;
	while (i < hill->ants)
	{
		hill->ants_move[i] = (t_ant *)malloc(sizeof(t_ant));
		hill->ants_move[i]->room_id = 0;
		hill->ants_move[i]->ant_num = -1;
		hill->ants_move[i]->way_id = -1;
		i++;
	}
	hill->ants_move[i] = NULL;
}

void	share_ants(t_into *hill, int index)
{
	int	id;
	int	ants;

	ants = 0;
	while (ants < hill->ants)
	{
		id = shortest_way(hill, hill->var_ways[index]);
		hill->tmp_ways[id]->c_ants++;
		hill->ants_move[ants]->way_id = id;
		ants++;
	}
}

void	give_ants_way_id(t_into *hill)
{
	int	id;

	id = best_var_id(hill);
	hill->steps = count_steps(hill, id);
	clean_ants(hill, id);
	create_ants_struct(hill);
	share_ants(hill, id);
}
