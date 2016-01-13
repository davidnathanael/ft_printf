/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 12:14:49 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

int				ft_get_args(t_options *options, va_list ap)
{
	unsigned long long		arg;

	if (options->type == UNS_OCTAL)
		arg = (va_arg(ap, unsigned int));
	if (options->type == UNS_LONG_OCTAL)
		arg = va_arg(ap, unsigned long);
	return (0);
}

t_options		*ft_get_options(char *format)
{
	t_options	*options;
	char		*subformat;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		return (NULL);
	subformat = ft_strsub(format, 0, ft_skip(format) + 1);
	if (!subformat)
	{
		free(options);
		return (NULL);
	}
	options->flags = ft_get_flags(subformat);
	options->width = ft_get_width(subformat);
	options->precision = ft_get_precision(subformat);
	options->modifier = ft_get_modifier(subformat);
	options->type = subformat[ft_strlen(subformat) - 1];
	free(subformat);
	return (options);
}

int				ft_do_format(char *format, va_list ap)
{
	(void)		ap;
	int			printed;
	t_options	*options;

	printed = 0;
	options = ft_get_options(format);
	if (format[1] == '%')
	{
		ft_putchar('%');
		free(options);
		return (1);
	}
	printed = ft_get_args(options, ap);
	free(options);
	//ft_print_options(options, ft_strsub(format, 0, ft_skip(format) + 1));
	return (printed);
}
