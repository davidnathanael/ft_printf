/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:43:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 10:16:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_putwchar(wchar_t c)
{
	int					i;
	unsigned long int	tmp;
	unsigned char		mask;
	unsigned char		tab[4];

	if ((mask = 127u) && c <= 0x7F)
	{
		ft_putchar((char)c);
		return (1);
	}
	if (!(i = 0) && c > 0x10FFFF)
		return (-1);
	while (c)
	{
		tmp = 63u & c;
		c = c >> 6;
		if (c)
			tab[i++] = tmp | 128u;
		else if ((mask = mask >> i))
			tab[i] = (tmp | (~mask)) & (~(64u >> i));
	}
	mask = (unsigned char)i + 1;
	while (i + 1 > 0)
		ft_putchar(tab[i--]);
	return (mask);
}
