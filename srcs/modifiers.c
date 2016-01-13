/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:14:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 10:19:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

	modifier = 0;
	if (ft_strstr(format, "ll"))
			modifier = M_LL;
	else if (ft_strchr(format, 'l'))
			modifier = M_L;
	else if (ft_strstr(format, "hh"))
			modifier = M_HH;
	else if (ft_strchr(format, 'h'))
			modifier = M_H;
	else if (ft_strchr(format, 'j'))
			modifier = M_J;
	else if (ft_strchr(format, 'z'))
			modifier = M_Z;
	return (modifier);
}
