/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 16:24:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "printf.h"
#include <inttypes.h>

int				ft_get_args(t_options *options, va_list ap)
{
	int	printed;
	intmax_t	int_arg;
	uintmax_t	uns_int_arg;

	printed = 0;
	if (NO_TYPE < options->type && options->type < T_UNS_INT)
		int_arg = ft_get_signed_args(options, ap);
	else if (T_INTMAX_T < options->type && options->type <= T_SIZE_T)
	uns_int_arg = ft_get_unsigned_args(options, ap);
	return (printed);
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
	options = ft_apply_modifier(options);
	printed = ft_get_args(options, ap);
	//ft_print_options(options, ft_strsub(format, 0, ft_skip(format) + 1));
	free(options);
	return (printed);
}
