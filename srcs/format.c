/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 11:22:02 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

t_bool		ft_skip(char *format);

int		ft_get_type(char *format, int skip, t_flags *flags, va_list ap)
{
	int		ret;

	ret = 0;
	if (format[skip] == 's')
		ret = ft_print_s(format, flags, ap);
	if (format[skip] == 'S')
		ret = ft_print_S(format, flags, ap);
	if (format[skip] == 'p')
		ret = ft_print_p(format, flags, ap);
	if (format[skip] == 'd' || format[skip] == 'i')
		ret = ft_print_d(format, flags, ap);
	if (format[skip] == 'D')
		ret = ft_print_D(format, flags, ap);
	if (format[skip] == 'o')
		ret = ft_print_o(format, flags, ap);
	if (format[skip] == 'O')
		ret = ft_print_O(format, flags, ap);
	if (format[skip] == 'u')
		ret = ft_print_u(format, flags, ap);
	if (format[skip] == 'U')
		ret = ft_print_U(format, flags, ap);
	if (format[skip] == 'x')
		ret = ft_print_x(format, flags, ap);
	if (format[skip] == 'X')
		ret = ft_print_X(format, flags, ap);
	if (format[skip] == 'c')
		ret = ft_print_c(format, flags, ap);
	if (format[skip] == 'C')
		ret = ft_print_C(format, flags, ap);
	return (ret);
}

int		ft_do_format(char *format, va_list ap)
{
	(void)	ap;
	int		skip;
	t_flags	*flags;

	skip = 1;
	if (format[1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	skip = ft_skip(format);
	flags = ft_get_flags(format, skip);
	ft_get_type(format, skip, flags, ap);
	return (skip);
}

t_bool		ft_skip(char *format)
{
	int		i;

	i = 1;
	while (ft_is_flag(format[i]) || ft_isdigit(format[i])
									|| ft_is_modifier(format[i]))
		i++;
	return (i);
}
