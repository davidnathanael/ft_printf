/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:47:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 10:33:53 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdio.h>

static t_flags		*ft_init_flags()
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->sharp = FALSE;
	flags->zero = FALSE;
	flags->minus = FALSE;
	flags->plus = FALSE;
	flags->space = FALSE;
	return (flags);
}

t_flags		*ft_get_flags(char *format, int skip)
{
	t_flags		*flags;

	flags = ft_init_flags();
	while (skip)
	{
		if (format[skip] == SHARP)
			flags->sharp = TRUE;
		if (format[skip] == ZERO)
			flags->zero = TRUE;
		if (format[skip] == MINUS)
			flags->minus = TRUE;
		if (format[skip] == PLUS)
			flags->plus = TRUE;
		if (format[skip] == SPACE)
			flags->space = TRUE;
		skip--;
	}
	return (flags);
}

t_bool		ft_has_flags(t_flags *flags)
{
	if (flags->sharp)
		return (TRUE);
	if (flags->zero)
		return (TRUE);
	if (flags->minus)
		return (TRUE);
	if (flags->plus)
		return (TRUE);
	if (flags->space)
		return (TRUE);
	return (FALSE);
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
