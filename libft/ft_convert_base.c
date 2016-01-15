/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 10:46:10 by lfabbro           #+#    #+#             */
/*   Updated: 2016/01/15 10:57:09 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_alloc_converted(char *str, size_t len)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	if (*str == '-')
		len++;
	ret = ft_strnew(len);
	ret = ft_strncpy(ret, str, len);
	return (ret);
}

char		*ft_convert_base(intmax_t num, unsigned int base)
{
	char		reb[128];
	char		*p;
	int			sign;
	size_t		count;

	p = &reb[sizeof(reb)];
	*p = '\0';
	sign = 0;
	count = 0;
	if ((int)num == 0)
		return ("0");
	if ((int)num < 0)
	{
		num = -num;
		sign = 1;
	}
	while (num != 0)
	{
		*--p = "0123456789abcdef"[num % base];
		num /= base;
		count++;
	}
	if (sign)
		*--p = '-';
	return (ft_alloc_converted(p, count));
}
