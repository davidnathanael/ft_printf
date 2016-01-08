/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:21:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/08 17:30:24 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdarg.h>
#include <stdio.h>
#include <libft.h>

static	void	ft_print(char *format, va_list ap, int nb_params)
{
	int		i;
	int		step;
	char	*fmt;

	i = 0;
	step = 1;
	fmt = format;
	while (fmt[i])
	{
		step = 1;
		if (fmt[i] == '%')
		{
			step += ft_do_format(&fmt[i], ap);
		}
		else
			ft_putchar(fmt[i]);
		i += step;
	}
	(void)nb_params;
}

static int ft_count_params(const char * restrict str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1] != '\0')
			count++;
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		i++;
	}
	return (count);
}

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
	ft_print((char *)format, ap, nb_params);
	va_end(ap);
	return (0);
}
