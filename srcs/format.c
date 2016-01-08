/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:28:56 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/08 16:54:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "printf.h"

t_bool		ft_is_flag(char c);
t_bool		ft_is_modifier(char c);

static int		ft_get_type(char *format, va_list ap)
{
	(void)ap;
	int		i;

	i = 0;
	while (ft_is_flag(format[i]) && ft_isdigit(format[i])
		&& ft_is_modifier(format[i]))
			i++;
	return (i + 1);
}

int		ft_do_format(char *format, va_list ap)
{
	(void)	ap;
	int		i;
	int		step;

	i = 0;
	if (format[1] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	step = ft_get_type(format, ap);
	ft_putchar('|');
	ft_putnbr(step);
	ft_putchar('|');
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
