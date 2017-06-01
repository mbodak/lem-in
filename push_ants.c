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



int		get_shortest_way(t_into *hill, t_var *ways)
{
	int		b;
	int		best;
	int		way_id;
	int		i;

	best = 1000000000;
	i = 0;
	way_id = 0;
	while (hill->tmp_ways && i < ways->length)
	{
		b = hill->tmp_ways[ways->indexes[i]]->w_len + hill->tmp_ways[ways->indexes[i]]->c_ants;
		if (b < best)
		{
			way_id = i;
			best = b;
		}
		i++;
	}
	return (way_id);
}

void	ants_choices_ways(t_into *hill)
{
	int		i;
	int 	ants;

	i = 0;
	while (hill->var_ways && i < hill->tmp_len)
	{
		if (hill->var_ways[i] == NULL)
		{
			i++;
			continue ;
		}
		if (i == hill->tmp_len)
			break ;
		ants = 0;
		while (ants < hill->ants)
		{
			hill->tmp_ways[get_shortest_way(hill, hill->var_ways[i])]->c_ants++;
			ants++;
		}
		i++;
	}

}

int 	count_steps(t_into *hill, int index) // return amount steps for var
{
	int i;
	int steps;

	ants_choices_ways(hill);
	steps = 0;
	i = 0;
	while (i < hill->var_ways[index]->length)
	{

		i++;
	}


	return (steps);
}

int		best_var_id(t_into *hill)
{
	int	i;
	int steps;
	int min_steps;
	int var_id;

	i = 0;
	var_id = 0;
	min_steps = count_steps(hill, i);
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
		if (steps <= min_steps)
		{
			min_steps = steps;
			var_id = i;
		}
		i++;
	}
	return (var_id);
}