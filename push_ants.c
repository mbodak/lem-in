/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:11:56 by mbodak            #+#    #+#             */
/*   Updated: 2017/06/08 22:40:41 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		empty_room(t_into *hill, int room_id, int way_id)
{
	int	i;
	int id;

	i = 0;
	while (hill->ants_move && hill->ants_move[i])
	{
		id = hill->ants_move[i]->way_id;
		if (hill->ants_move[i]->room_id == room_id && id == way_id &&
				hill->tmp_ways[id]->way[room_id] != hill->end)
			return (0);
		i++;
	}
	return (1);
}

void	push_ants(t_into *hill, int j, int k)
{
	int room_id;
	int id1;
	int id2;

	while (hill->ants_move && hill->ants_move[j])
	{
		room_id = hill->ants_move[j]->room_id + 1;
		if (room_id < hill->tmp_ways[hill->ants_move[j]->way_id]->w_len)
		{
			if (empty_room(hill, room_id, hill->ants_move[j]->way_id))
			{
				hill->ants_move[j]->room_id = room_id;
				hill->ants_move[j]->ant_num = j + 1 - k;
				id1 = hill->ants_move[j]->way_id;
				id2 = hill->ants_move[j]->room_id;
				ft_printf("L%d-%s ", hill->ants_move[j]->ant_num,
						hill->rooms[hill->tmp_ways[id1]->way[id2]]->name);
			}
			else
				k++;
		}
		j++;
	}
}

int		is_end_room(t_into *hill)
{
	int i;
	int id1;
	int id2;
	int id3;

	i = 0;
	while (hill->ants_move[i])
	{
		id1 = hill->ants_move[i]->way_id;
		id2 = hill->ants_move[i]->room_id;
		id3 = hill->tmp_ways[id1]->way[id2];
		if (hill->rooms[id3]->name != hill->rooms[hill->end]->name)
			return (0);
		i++;
	}
	return (1);
}

void	print_ants(t_into *hill)
{
	int i;

	give_ants_way_id(hill);
	i = 0;
	while (i < hill->steps)
	{
		push_ants(hill, 0, 0);
		if (!is_end_room(hill))
			ft_printf("\n");
		else
			return ;
		i++;
	}
}
