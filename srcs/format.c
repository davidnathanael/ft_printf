/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 15:47:07 by ddela-cr         ###   ########.fr       */
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
	int	printed;
	(void)options;
	(void)ap;

	printed = 0;
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
	options->specifier = subformat[ft_strlen(subformat) - 1];
	options->type = 0;
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
	if (!options)
		return (ERROR);
	if (format[1] == '%')
	{
		ft_putchar('%');
		free(options);
		return (1);
	}
	printed = ft_get_args(options, ap);
	options = ft_apply_modifier(options);
	ft_print_options(options, ft_strsub(format, 0, ft_skip(format) + 1));
	free(options);
	return (printed);
}
