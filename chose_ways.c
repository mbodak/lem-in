/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:29:06 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/28 21:29:08 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//int		find_all_ways(t_into *hill)
//{
//	int		count;
//	t_way	*way;
//
//
//	count = 0;
//
//	return (count);
//}

int		detect_matches(t_way *way1, t_way *way2)
{
	int i;
	int j;

	i = 0;
	while (way1->way && i < way1->w_len)
	{
		j = 0;
		while (way2->way && j < way2->w_len)
		{
			if (way1->way[i] == way2->way[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//int 	is_parallel_way(int index, t_way **ways)
//{
//	if (detect_matches())
//		return (0);
//	return (1);
//}

int		add_parallel_way(t_into *hill, t_way *way)
{
	int	i;

	i = 0;


}

int 	add_new_var(t_into *hill, t_way *way)
{

}

void	get_var_ways(t_into *hill)
{
	int	i;
	int	j;

	i = 0;
	while (hill->tmp_ways && i < hill->tmp_len)
	{
		add_new_var(hill, hill->tmp_ways[i]);
		j = 0;
		while (j < hill->tmp_len)
		{
			if (i == j)
				j++;
			if (!detect_matches(hill->tmp_ways[i], hill->tmp_ways[j]))
				add_parallel_way(hill, hill->tmp_ways[j]);
			j++;
		}
		i++;
	}
}






void	get_all_posible_ways(t_into *hill)
{
	int i;

	find_ways(hill);
	i = 0;
	while (hill->tmp_ways && hill->tmp_ways[i])
	{
		hill->tmp_ways[i]->matches = count_matches(i, hill->tmp_ways);
		i++;
	}

}






int		find_shortest(t_into *hill)
{
	int		b;
	int		best;
	int		best_id;
	int		j;

	best = 1000000000;
	j = 0;
	best_id = 0;
	while (hill->ways && hill->ways[j])
	{
		b = hill->ways[j]->w_len + hill->ways[j]->c_ants;
		if (b < best)
		{
			best_id = j;
			best = b;
		}
		j++;
	}
	return (best_id);
}

void	chose_ways(t_into *hill)
{
	int		i;

	i = 0;
	while (i < hill->ants)
	{
		hill->ways[find_shortest(hill)]->c_ants++;
		i++;
	}
}
