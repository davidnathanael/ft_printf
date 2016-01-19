/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:17:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 10:30:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstr(wchar_t *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		ft_putwchar(str[index]);
		index++;
		if (str[index])
			return (--index);
	}
	return (index);
}
