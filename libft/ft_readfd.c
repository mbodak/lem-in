/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:29:23 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/22 16:21:44 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfd(int fd)
{
	ssize_t	size;
	char	buffer[BUFFER_SIZE + 1];
	char	*result;
	char	*tmp;

	result = ft_strdup("");
	while ((size = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[size] = '\0';
		tmp = result;
		result = ft_strjoin(result, buffer);
		free(tmp);
	}
	return (result);
}
