/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 15:33:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

static int		ft_get_arg(char *format, char type)
{
	int		ret;
	(void)format;
	(void)type;

	ret = 0;
	return (ret);
}

int				ft_do_format(char *format, va_list ap)
{
	(void)		ap;
	int			printed;
	char		type;
	t_modifier	modifier;

	printed = 0;
	type = format[ft_skip(format)];
	modifier = ft_get_modifier(format);
	if (format[1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	printed = ft_get_arg(format, type);
	return (printed);
}
