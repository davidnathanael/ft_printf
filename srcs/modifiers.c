/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:14:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 15:59:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

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

int		ft_get_modifier(char *format)
{
	t_modifier	modifier;
	char		str[99];
	(void)str;

	modifier = 0;
	//ft_strncpy(str, format, ft_skip(format) + 1);
	//CONTINUE HERE
	ft_putstr("\n---------|");
	ft_putstr(format);
	ft_putstr("|---------\n");
	return (modifier);
}
