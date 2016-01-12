/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:14:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 11:22:11 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_sharp_flag(char type, int nb)
{
	char	*ret;

	ret = ft_itoa(nb);
	if (nb)
	{
		if (type == UNS_OCTAL)
			ret = ft_strjoin("0", ret);
		if (type == UNS_HEXA)
			ret = ft_strjoin("0x", ret);
		if (type == UNS_LONG_HEXA)
			ret = ft_strjoin("0X", ret);
	}
	return (ret);
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
