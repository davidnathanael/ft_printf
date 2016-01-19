/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 21:59:39 by ddela-cr         ###   ########.fr       */
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
	if (ft_strchr("sSpdDioOuUxXcC", format[ft_skip(format)]) == NULL)
	{
		while (*(++format) == ' ' && *format)
			;
		return (FALSE);
	}
	if (ft_strcmp(format, "%") == 0)
		return (FALSE);
	return (TRUE);
}

static int		ft_print(char *format, va_list ap)
{
	int		i;
	int		printed;
	char	*fmt;

	i = 0;
	printed = 0;
	fmt = format;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ft_is_valid_percent(fmt))
			{
				printed += ft_do_format(fmt, ap);
				fmt += ft_skip(fmt);
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
