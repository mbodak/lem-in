/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:48:58 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/19 15:49:02 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define FD 0
# include "libft/libft.h"

typedef enum		e_command
{
	NON,
	START,
	END
}					t_command;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

typedef struct		s_link
{
	int				name1;
	int				name2;
}					t_link;

typedef struct		s_way
{
	int				*way;
	int				w_len;
	int				c_ants;
	int 			matches;
}					t_way;

typedef struct 		s_ant
{
	int 			ant_num;
	int 			room;
	int 			way_id;

}					t_ant;

typedef struct		s_into
{
	int				ants;
	char			**data;
	int				start;
	int				end;
	t_room			**rooms;
	t_link			**links;
	t_way			**ways;
	t_way			**tmp_ways;
	int 			tmp_len;
	t_way			***var_ways;
	t_ant			**ants_move;
	int				**matrix;
	int				m_len;
}					t_into;

int					is_comment(char *string);
t_command			is_command(char *string);
int					is_digit(char *string);
int					parse_links(t_into *hill, int i);
int					cmp_n(t_into *hill, char *string);
int					parser(t_into *hill);
void				fill_matrix(t_into *hill);
void				find_ways(t_into *hill);
//int					add_way(t_into *hill, t_way *way);
void				remove_way_from_matrix(t_into *hill, t_way *way);
int					find_all_ways(t_into *hill);
int					find_shortest(t_into *hill);
void				chose_ways(t_into *hill);
int					push_ants(t_into *hill);
void				free_memory(t_into *hill);

#endif
