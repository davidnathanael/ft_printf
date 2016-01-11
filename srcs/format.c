/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/11 09:39:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

t_bool		ft_is_flag(char c);
t_bool		ft_is_modifier(char c);
t_bool		ft_skip(char *format);
int		ft_get_type(char *format, int skip, va_list ap)
{
	int		ret;

	ret = 0;
	if (format[skip] == 's')
		ret = ft_print_s(format, ap);
	if (format[skip] == 'S')
		ret = ft_print_S(format, ap);
	if (format[skip] == 'p')
		ret = ft_print_p(format, ap);
	if (format[skip] == 'd' || format[skip] == 'i')
		ret = ft_print_d(format, ap);
	if (format[skip] == 'D')
		ret = ft_print_D(format, ap);
	if (format[skip] == 'o')
		ret = ft_print_o(format, ap);
	if (format[skip] == 'O')
		ret = ft_print_O(format, ap);
	if (format[skip] == 'u')
		ret = ft_print_u(format, ap);
	if (format[skip] == 'U')
		ret = ft_print_U(format, ap);
	if (format[skip] == 'x')
		ret = ft_print_x(format, ap);
	if (format[skip] == 'X')
		ret = ft_print_X(format, ap);
	if (format[skip] == 'c')
		ret = ft_print_c(format, ap);
	if (format[skip] == 'C')
		ret = ft_print_C(format, ap);
	return (ret);
}

int		ft_do_format(char *format, va_list ap)
{
	(void)	ap;
	int		step;

	step = 1;
	if (format[1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	step = ft_skip(format);
	ft_get_type(format, step, ap);
	return (step);
}

t_bool		ft_is_flag(char c)
{
	if (c == ' ')
		return (TRUE);
	if (c == '+')
		return (TRUE);
	if (c == '-')
		return (TRUE);
	if (c == '#')
		return (TRUE);
	if (c == '0')
		return (TRUE);
	if (c == '.')	//precision
		return (TRUE);
	return (FALSE);
}

t_bool		ft_is_modifier(char c)
{
	if (c == 'l')
		return (TRUE);
	if (c == 'h')
		return (TRUE);
	if (c == 'j')
		return (TRUE);
	if (c == 'z')
		return (TRUE);
	return (FALSE);
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
