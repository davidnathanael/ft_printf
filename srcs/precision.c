/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:26:34 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 11:12:27 by ddela-cr         ###   ########.fr       */
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

int		ft_get_width(char *format)
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
	while (!ft_isdigit(*fmt) && *fmt)
	{
		fmt++;
		if (*fmt == F_ZERO)
			fmt++;
	}
	while (ft_isdigit(*fmt) && *fmt)
		tmp[i++] = *(fmt++);
	if (i > 0)
		ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}
