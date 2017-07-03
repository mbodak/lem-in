/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:29:50 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/20 19:29:52 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_command	is_command(char *string)
{
	if (ft_strequ(string, "##start"))
		return (START);
	if (ft_strequ(string, "##end"))
		return (END);
	return (NON);
}

int			is_comment(char *string)
{
	if (string[0] == '#' && !is_command(string))
		return (1);
	return (0);
}

int			is_digit(char *string)
{
	int		j;

	j = 0;
	while (string[j])
	{
		if (!ft_isdigit(string[j]))
			return (0);
		j++;
	}
	return (1);
}

int			ft_free_arr(char **arr, int i)
{
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
