/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/18 19:53:23 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdarg.h>
#include <stdio.h>
#include <libft.h>

t_bool		ft_skip(char *format)
{
	int		i;

	i = 1;
	while (ft_is_flag(format[i]) || ft_isdigit(format[i])
									|| ft_is_modifier(format[i]))
		i++;
	return (i);
}

static int		ft_print(char *format, va_list ap)
{
	int		i;
	int		printed;
	char	*fmt;

	i = 0;
	printed = 0;
	fmt = format;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			printed += ft_do_format(&fmt[i], ap);
			i += ft_skip(&fmt[i]) + 1;
			continue ;
		}
		else
		{
			ft_putchar(fmt[i]);
			printed++;
		}
		i++;
	}
	return (printed);
}

int 			ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	if (!ft_strchr((char *)format, '%'))
	{
		ft_putstr((char *)format);
		return ((int)ft_strlen(format));
	}
	va_start(ap, format);
		ret = ft_print((char *)format, ap);
	va_end(ap);
	return (ret);
}
