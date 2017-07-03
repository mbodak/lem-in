/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_parallel_ways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 22:14:26 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/08 22:14:28 by mbodak           ###   ########.fr       */
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
			if (way1->way[i] == way2->way[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	add_variant(t_into *hill, int *ind, int l, int len)
{
	t_var	*var;
	t_var	**variants;

	var = (t_var *)malloc(sizeof(t_var));
	var->indexes = (int *)malloc(sizeof(int) * l);
	var->length = l;
	while (len < l)
	{
		var->indexes[len] = ind[len];
		len++;
	}
	len = 0;
	while (hill->var_ways && hill->var_ways[len])
		len++;
	variants = (t_var **)malloc(sizeof(t_var *) * (len + 2));
	variants[len] = var;
	variants[len + 1] = NULL;
	while (hill->var_ways && len > 0)
	{
		len--;
		variants[len] = hill->var_ways[len];
	}
	if (hill->var_ways)
		free(hill->var_ways);
	hill->var_ways = variants;
}

int		is_parallel(t_into *hill, int *arr, int i, t_way *way)
{
	int j;
	int id;

	j = 0;
	while (j < i)
	{
		id = arr[j];
		if (detect_matches(hill->tmp_ways[id], way, hill))
			return (0);
		j++;
	}
	return (1);
}

void	add_parallel(t_into *hill, int *arr, int i, int way_id)
{
	int	j;
	int	flag;

	arr[i] = way_id;
	flag = 1;
	j = 0;
	while (j < hill->tmp_len)
	{
		if (is_parallel(hill, arr, i + 1, hill->tmp_ways[j]))
		{
			add_parallel(hill, arr, i + 1, j);
			flag = 0;
		}
		j++;
	}
	if (flag)
		add_variant(hill, arr, i + 1, 0);
}

void	find_parallel(t_into *hill)
{
	int *arr;
	int v;

	arr = (int *)malloc(sizeof(int) * hill->tmp_len);
	hill->var_ways = NULL;
	v = 0;
	while (v < hill->tmp_len)
	{
		add_parallel(hill, arr, 0, v);
		v++;
	}
	free(arr);
}
