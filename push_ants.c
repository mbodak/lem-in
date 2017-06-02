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

//void	add_ants(t_into *hill)
//{
//	int 	i;
//	int 	j;
//	int 	ant_num;
//
//	hill->ants_move = (t_ant **)malloc(sizeof(t_ant) * (hill->ants + 1));
//	chose_ways(hill);
//	i = 0;
//	ant_num = 1;
//	while (i < hill->ants)
//	{
//		j = 0;
//		while (hill->ways[j])
//		{
//			hill->ants_move[i] = (t_ant *)malloc(sizeof(t_ant));
//			hill->ants_move[i]->room = hill->start;
//			hill->ants_move[i]->ant_num = ant_num++;
//			hill->ants_move[i]->way_id = j;
//			j++;
//		}
//		i++;
//	}
//	hill->ants_move[i] = NULL;
//}



int		shortest_way(t_into *hill, t_var *ways)
{
	int		b;
	int		best;
	int		way_id;
	int		i;

	best = INFINITY;
	i = 0;
	way_id = 0;
	while (hill->tmp_ways && i < ways->length)
	{
		b = (hill->tmp_ways[ways->indexes[i]]->w_len - 2) +
				hill->tmp_ways[ways->indexes[i]]->c_ants;
		if (b < best)
		{
			best = b;
			way_id = i;
		}
		i++;
	}
	return (way_id);
}

void	ants_choices_ways(t_into *hill, int index)
{
	int		i;
	int		id;
	int 	ants;

	i = 0;
	while (hill->var_ways && i < hill->var_ways[index]->length)
	{
		ants = 0;
		while (ants < hill->ants)
		{
			id = shortest_way(hill, hill->var_ways[index]);
			hill->tmp_ways[id]->c_ants++;
			ants++;
		}
		i++;
	}
}

int 	steps_in_way(t_into *hill, int id_way)
{
	int steps;

	steps = 0;
	if (hill->tmp_ways[id_way]->c_ants > 0)
		steps = (hill->tmp_ways[id_way]->w_len - 2) +
				hill->tmp_ways[id_way]->c_ants;
	return (steps);
}

int 	count_steps(t_into *hill, int index) // return amount steps for var
{
	int i;
	int steps;
	int steps_max;

	ants_choices_ways(hill, index);
	steps_max = 0;
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

int		best_var_id(t_into *hill)
{
	int	i;
	int steps;
	int min_steps;
	int var_id;

	var_id = 0;
	i = 0;
	min_steps = INFINITY;
	while (hill->var_ways && i < hill->tmp_len)
	{
		if (hill->var_ways[i] == NULL)
		{
			i++;
			continue ;
		}
		if (i == hill->tmp_len)
			break ;
		steps = count_steps(hill, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			var_id = i;
		}
//		for (int j = 0; j < hill->tmp_len; j++)
//			hill->tmp_ways[j]->c_ants = 0;
		i++;
	}
	steps = count_steps(hill, var_id);
	return (var_id);
}
