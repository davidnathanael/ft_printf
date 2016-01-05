/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/04 21:07:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdarg.h>
#include <stdio.h>
#include <libft.h>

int ft_printf(const char * restrict format, ...)
{
	int			nb_params;
	va_list		ap;
	int	i;

	i = 0;
	nb_params = ft_count_params(format);
	if (nb_params == 0)
		ft_putstr((char *)format);
	va_start(ap, format);
	while (i < nb_params)
	{
		printf("%d\n", va_arg(ap, int));
		i++;
	}
	va_end(ap);
	return (0);
}

int ft_count_params(const char * restrict str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}
