/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:52:05 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/05 18:52:08 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean_ants(t_into *hill, int index)
{
	int	j;

	j = 0;
	while (j < hill->var_ways[index]->length)
	{
		hill->tmp_ways[hill->var_ways[index]->indexes[j]]->c_ants = 0;
		j++;
	}
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
	while (hill->var_ways && hill->var_ways[i])
	{
		steps = count_steps(hill, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			var_id = i;
		}
		clean_ants(hill, i);
		i++;
	}
	return (var_id);
}
