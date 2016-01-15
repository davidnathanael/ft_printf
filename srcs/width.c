/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:28:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 23:03:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

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
