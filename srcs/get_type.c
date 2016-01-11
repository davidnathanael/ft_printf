/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 08:38:09 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/11 09:43:24 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <wchar.h>

int		ft_print_s(char *format, va_list ap)
{
	char	*str;
	(void)format;

	str = va_arg(ap, char *);
	ft_putstr(str);
	return (0);
}

int		ft_print_S(char *format, va_list ap)
{
	wchar_t		*str;
	(void)format;

	str = va_arg(ap, wchar_t *);
	(void)str;
	return (0);
}

int		ft_print_p(char *format, va_list ap)
{
	void	*ptr;
	(void)format;

	ptr = va_arg(ap, void *);
	(void)ptr;
	return (0);
}

int		ft_print_d(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_D(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_o(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_O(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_u(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_U(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_x(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_X(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_c(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}

int		ft_print_C(char *format, va_list ap)
{
	int		nbr;
	(void)format;

	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	return (0);
}
