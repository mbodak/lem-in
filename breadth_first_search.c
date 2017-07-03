/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:45:21 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/26 11:45:26 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*create_new_way(int l)
{
	t_way	*new_way;

	new_way = (t_way *)malloc(sizeof(t_way));
	new_way->way = (int *)malloc(sizeof(int) * (l + 1));
	new_way->c_ants = 0;
	new_way->w_len = 0;
	return (new_way);
}

int		save_way(t_into *hill, int *w, int l, int len)
{
	t_way	*new_way;
	t_way	**ways;

	while (hill->tmp_ways && hill->tmp_ways[len])
		len++;
	ways = (t_way **)malloc(sizeof(t_way *) * (len + 2));
	len = 0;
	while (hill->tmp_ways && hill->tmp_ways[len])
	{
		ways[len] = hill->tmp_ways[len];
		len++;
	}
	new_way = create_new_way(l);
	ways[len + 1] = NULL;
	while (new_way->w_len <= l)
	{
		new_way->way[new_way->w_len] = w[new_way->w_len];
		new_way->w_len++;
	}
	ways[len] = new_way;
	if (hill->tmp_ways)
		free(hill->tmp_ways);
	hill->tmp_ways = ways;
	return (len + 1);
}

void	bfs(int v, t_into *hill, int rear, int *visited)
{
	int		i;

	visited[v] = 1;
	hill->stack[rear] = v;
	if (v == hill->end)
		hill->tmp_len = save_way(hill, hill->stack, rear, 0);
	i = 0;
	while (i < hill->m_len)
	{
		if (!visited[i] && hill->matrix[v][i] == 1)
			bfs(i, hill, rear + 1, visited);
		i++;
	}
	visited[v] = 0;
}

void	check_min_way(t_into *hill)
{
	int	j;
	int i;

	i = 0;
	while (hill->tmp_ways[i])
	{
		if (hill->tmp_ways[i]->w_len == 2)
		{
			j = 0;
			while (hill->tmp_ways[j])
			{
				if (i != j)
				{
					free(hill->tmp_ways[j]->way);
					free(hill->tmp_ways[j]);
				}
				j++;
			}
			hill->tmp_ways[0] = hill->tmp_ways[i];
			hill->tmp_ways[1] = NULL;
			hill->tmp_len = 1;
			break ;
		}
		i++;
	}
}

int		find_ways(t_into *hill)
{
	int		*visited;

	hill->stack = (int *)malloc(sizeof(int) * hill->m_len);
	visited = (int *)malloc(sizeof(int) * hill->m_len);
	ft_memset(visited, 0, ((size_t)hill->m_len * sizeof(int)));
	hill->tmp_ways = NULL;
	if (hill->start < 0 || hill->end < 0)
		return (0);
	bfs(hill->start, hill, 0, visited);
	free(visited);
	if (hill->tmp_ways == NULL)
		return (0);
	check_min_way(hill);
	return (1);
}
