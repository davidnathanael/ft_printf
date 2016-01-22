/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:26:34 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/21 23:20:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "printf.h"
#include "libft.h"

int		ft_get_precision(char *format)
{
	int		i;
	int		ret;
	char	*fmt;
	char	*tmp;

	i = 0;
	ret = -1;
	fmt = format;
	tmp = ft_strnew(ft_strlen(format));
	if (!tmp)
		return (ERR_STRNEW);
	if ((fmt = ft_strchr(fmt, '.')))
	{
		while (++fmt && *fmt && ft_isdigit(*fmt))
			tmp[i++] = *fmt;
		if (i == 0)
			ret = 0;
	}
	if (i > 0)
		ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

static char	*ft_prepend_zero(t_precision precision, char *arg)
{
	char	*ret;
	char	*arg_tmp;
	size_t	i;
	size_t	len_zero;
	t_bool	is_negative;

	ret = NULL;
	arg_tmp = arg;
	i = 0;
	len_zero = (size_t)precision - ft_strlen(arg);
	is_negative = arg_tmp[0] == '-' ? TRUE : FALSE;
	ret = ft_strnew(is_negative + precision);
	if (is_negative)
	{
		ret[i++] = '-';
		len_zero += 2;
		arg_tmp++;
	}
	while (i < len_zero)
		ret[i++] = '0';
	while (*arg_tmp)
		ret[i++] = *(arg_tmp++);
	return (ret);
}

char	*ft_apply_precision(t_options *options, char *arg)
{
	char	*ret;
	size_t	len;

	ret = NULL;
	len = ft_strlen(arg);
	if ((int)len < options->precision)
	{
		if (len < (size_t)options->precision)
			ret = ft_prepend_zero(options->precision, arg);
		return (ret);
	}
	else if (options->precision == 0)
	{
		if (ft_atoi(arg) == 0)
			return (ft_strdup(""));
	}
	return (arg);
}
