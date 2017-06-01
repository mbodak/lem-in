/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:47:57 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/19 15:48:00 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**reading(void)
{
	char	*fd;
	char	**data;

	fd = ft_readfd(FD);
	data = ft_strsplit(fd, '\n');
	free(fd);
	return (data);
}

t_into	*create_hill(void)
{
	t_into	*hill;

	hill = (t_into *)malloc(sizeof(t_into));
	hill->ants = -1;
	hill->data = reading();
	hill->start = -1;
	hill->end = -1;
	hill->rooms = NULL;
	hill->links = NULL;
//	hill->ways = NULL;
	hill->tmp_ways = NULL;
	hill->tmp_len = 0;
	hill->var_ways = NULL;
	hill->ants_move = NULL;
	hill->matrix = NULL;
	hill->m_len = 0;
	return (hill);
}

void	print_matrix(t_into *hill)
{
	int		i;
	int		j;

	i = 0;
	while (i < hill->m_len)
	{
		j = 0;
		while (j < hill->m_len)
		{
			ft_printf("%d ", hill->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_ways(t_into *hill)
{
	int	j;
	int	i;

	i = 0;
	while (hill->tmp_ways[i])
	{
		ft_printf("WAY %d\n", i + 1);
		ft_printf("{\n");
		j = 0;
		ft_printf("\tway: ");
		while (j < hill->tmp_ways[i]->w_len)
		{
			ft_printf("%d ", hill->tmp_ways[i]->way[j]);
			j++;
		}
		ft_printf("\n");
		ft_printf("\tlen: %d\n", hill->tmp_ways[i]->w_len);
		ft_printf("\tants: %d\n", hill->tmp_ways[i]->c_ants);
		ft_printf("}\n");
		i++;
	}
}

void	print_var(t_into *hill)
{
	int	j;
	int	i;

	i = 0;
	ft_printf("%d \n", hill->tmp_len);
	while (i < hill->tmp_len)
	{
		if (hill->var_ways[i])
		{
			ft_printf("VAR WAY %d\n", i + 1);
			ft_printf("{\n");
			j = 0;
			ft_printf("\tway: ");
			while (j < hill->var_ways[i]->length)
			{
				ft_printf("%d ", hill->var_ways[i]->indexes[j]);
				j++;
			}
			ft_printf("\n\tlength: %d", hill->var_ways[i]->length);
			ft_printf("\n");
			ft_printf("}\n");
		}
		i++;
	}
}

int		main(void)
{
	t_into	*hill;

	hill = create_hill();
	parser(hill);
	fill_matrix(hill);
	print_matrix(hill);
//	if (!find_all_ways(hill))
//	{
//		ft_printf("ERROR\n");
//		return (0);
//	}
//	chose_ways(hill);
	find_ways(hill);
	print_ways(hill);
//	find_parallel_ways(hill);
	choice_variants(hill);
//	sort_ways(hill);
	print_var(hill);
//	push_ants(hill);
//	free_memory(hill);
//	free(hill);
	return (0);
}
