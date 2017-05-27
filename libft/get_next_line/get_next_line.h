/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:22:59 by mbodak            #+#    #+#             */
/*   Updated: 2017/02/03 11:24:39 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <gssapi.h>
# include "../libft.h"

typedef struct		s_line
{
	char			*remain;
	struct s_line	*next;
	int				fd;
}					t_line;
char				*read_line(int fd);
int					check_fd(int fd, t_line *begin_list);
t_line				*create_elem(int fd);
void				elem_add(int fd, t_line **begin_list);

#endif
