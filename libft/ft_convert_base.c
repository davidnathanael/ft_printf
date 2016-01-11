/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 10:46:10 by lfabbro           #+#    #+#             */
/*   Updated: 2016/01/11 10:32:32 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_convert_base(unsigned int num, unsigned int base)
{
	static char		reb[33];
	char		*p;
	int			sign;

	p = &reb[sizeof(reb)];
	*p = '\0';
	sign = 0;
	if ((int)num == 0)
		return ("0");
	if ((int)num < 0)
	{
		num = -num;
		sign = 1;
	}
	while (num != 0)
	{
		*--p = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	if (sign)
		*--p = '-';
	return (p);
}
