/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:32:07 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:32:13 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*str_width(char *str, t_saver *saver)
{
	char	*tmp;
	int		i;

	if ((saver->width > 0) && (saver->width > (int)ft_strlen(str)))
	{
		saver->width = saver->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)saver->width);
		i = 0;
		while (i < saver->width)
		{
			if (saver->minus_null == '0')
				tmp[i] = '0';
			else
				tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		if (saver->minus_null == '-')
			str = ft_joinfree(str, tmp, FIRST);
		else
			str = ft_joinfree(tmp, str, SECOND);
		free(tmp);
	}
	return (str);
}

static char		*str_precision(char *str, t_saver *saver)
{
	char	*res;
	int		i;

	if ((saver->precision >= 0) && (saver->precision < (int)ft_strlen(str)))
	{
		i = 0;
		res = ft_strnew((size_t)saver->precision);
		while (i < saver->precision)
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (str);
}

void			print_string(t_saver *saver, va_list arg)
{
	char	*str;

	if (saver->size == L)
		str = convert_wstrtostr(va_arg(arg, wchar_t *), saver->precision);
	else
	{
		str = va_arg(arg, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	str = str_precision(str, saver);
	str = str_width(str, saver);
	ft_put_string(str);
	free(str);
}
