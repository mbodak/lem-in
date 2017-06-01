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

int		detect_matches(t_way *way1, t_way *way2, t_into *hill)
{
	int i;
	int j;

	i = 0;
	while (way1->way && i < way1->w_len)
	{
		if (way1->way[i] == hill->start || way1->way[i] == hill->end)
			i++;
		if (i == way1->w_len)
			return (0);
		j = 0;
		while (way2->way && j < way2->w_len)
		{
			if (way2->way[i] == hill->start || way2->way[i] == hill->end)
				j++;
			if (way1->way[i] == way2->way[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	add_new_var(t_into *hill, int i)
{
	if (hill->var_ways == NULL)
		hill->var_ways = (t_var **)malloc(sizeof(t_var *) * hill->tmp_len);
	hill->var_ways[i] = (t_var *)malloc(sizeof(t_var));
	hill->var_ways[i]->indexes = (int *)malloc(sizeof(int) * hill->tmp_len);
	hill->var_ways[i]->indexes[0] = i;

}

void	find_parallel_ways(t_into *hill)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (hill->tmp_ways && i < hill->tmp_len)
	{
		add_new_var(hill, i);
		j = 0;
		k = 0;
		while (j < hill->tmp_len)
		{
			if (i == j)
				j++;
			if (j == hill->tmp_len)
				break ;
			if (!detect_matches(hill->tmp_ways[i], hill->tmp_ways[j], hill))
			{
				k++;
				hill->var_ways[i]->indexes[k] = j;
			}
			j++;
		}
		hill->var_ways[i]->length = k + 1;
		i++;
	}
}

void	sort_ways(t_into *hill)
{
	int i;

	find_parallel_ways(hill);
	i = 0;
	while (i < hill->tmp_len)
	{
		ft_bubble_sort(hill->var_ways[i]->indexes, hill->var_ways[i]->length);
		i++;
	}
}

int		compare_ways(t_var *var1, t_var *var2)
{
	int i;

	if (var1->length != var2->length)
		return (0);
	i = 0;
	while (i < var1->length)
	{
		if (var1->indexes[i] != var2->indexes[i])
			return (0);
		i++;
	}
	return (1);
}

void	choice_variants(t_into *hill)
{
	int i;
	int j;

	sort_ways(hill);
	i = 0;
	while (i < hill->tmp_len)
	{
		if (hill->var_ways[i] == NULL)
		{
			i++;
			continue ;
		}
		if (i == hill->tmp_len)
			break ;
		j = 0;
		while (j < hill->tmp_len)
		{
			if (j == i || hill->var_ways[j] == NULL)
			{
				j++;
				continue ;
			}
			if (j == hill->tmp_len)
				break ;
			if (compare_ways(hill->var_ways[i], hill->var_ways[j]))
			{
				free(hill->var_ways[j]->indexes);
				free(hill->var_ways[j]);
				hill->var_ways[j] = NULL;
			}

			j++;
		}
		i++;
	}
}
