/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 09:35:51 by ddela-cr         ###   ########.fr       */
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
	while ((ft_is_flag(format[i]) || ft_isdigit(format[i])
			|| ft_is_modifier(format[i])) && format[i])
		i++;
	return (i);
}

static t_bool	ft_is_valid_percent(char *format)
{
	if (ft_strcmp(format, "%") == 0)
		return (FALSE);
	return (TRUE);
}

static int		ft_print(char *format, va_list ap)
{
	int		ret_do_format;
	int		printed;
	char	*fmt;

	ret_do_format = 0;
	printed = 0;
	fmt = format;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ft_is_valid_percent(fmt))
			{
				ret_do_format = ft_do_format(fmt, ap);
				if (ret_do_format == ERROR)
					return (ERROR);
				else
				{
					printed += ret_do_format;
					fmt += ft_skip(fmt);
				}
			}
		}
		else
		{
			ft_putchar(*fmt);
			printed++;
		}
		fmt++;
	}
	return (printed);
}

int			ft_printf(const char * restrict format, ...)
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
