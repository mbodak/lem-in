/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 22:23:47 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/08 22:23:49 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		shortest_way(t_into *hill, t_var *ways)
{
	int	b;
	int	best;
	int	way_id;
	int	i;
	int	curr_id;

	best = INFINITY;
	i = 0;
	way_id = -1;
	while (hill->tmp_ways && i < ways->length)
	{
		curr_id = ways->indexes[i];
		b = (hill->tmp_ways[curr_id]->w_len - 2) +
			hill->tmp_ways[curr_id]->c_ants;
		if (b < best)
		{
			best = b;
			way_id = curr_id;
		}
		i++;
	}
	return (way_id);
}

void	ants_choices_ways(t_into *hill, int index)
{
	int	id;
	int	ants;

	ants = 0;
	while (ants < hill->ants)
	{
		id = shortest_way(hill, hill->var_ways[index]);
		hill->tmp_ways[id]->c_ants++;
		ants++;
	}
}

int		steps_in_way(t_into *hill, int id_way)
{
	int steps;

	steps = 0;
	if (hill->tmp_ways[id_way]->c_ants > 0)
		steps = (hill->tmp_ways[id_way]->w_len - 2) +
				hill->tmp_ways[id_way]->c_ants;
	return (steps);
}

int		count_steps(t_into *hill, int index)
{
	int i;
	int steps;
	int steps_max;

	ants_choices_ways(hill, index);
	steps_max = -1;
	i = 0;
	while (i < hill->var_ways[index]->length)
	{
		steps = steps_in_way(hill, hill->var_ways[index]->indexes[i]);
		if (steps_max < steps)
			steps_max = steps;
		i++;
	}
	return (steps_max);
}
