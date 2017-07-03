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
	hill->stack = NULL;
	hill->tmp_ways = NULL;
	hill->tmp_len = 0;
	hill->var_ways = NULL;
	hill->ants_move = NULL;
	hill->matrix = NULL;
	hill->m_len = 0;
	hill->steps = 0;
	return (hill);
}

void	print_data(t_into *hill, int last)
{
	int i;

	i = 0;
	while (hill->data && hill->data[i])
	{
		if (i < last)
			ft_printf("%s\n", hill->data[i]);
		i++;
	}
	ft_printf("\n");
}

int		main(void)
{
	int		i;
	t_into	*hill;

	hill = create_hill();
	i = parser(hill, 0);
	fill_matrix(hill);
	if (i == 0 || !find_ways(hill))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	print_data(hill, i);
	find_parallel(hill);
	print_ants(hill);
	ft_printf("\n");
	free_memory(hill);
	free(hill);
	sleep(7);
	return (0);
}
