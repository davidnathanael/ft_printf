/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 08:38:09 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 12:10:17 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "printf.h"
#include "libft.h"

int		ft_print_s(char *format, t_flags *flags, va_list ap)
{
	char	*str;
	(void)format;

	str = va_arg(ap, char *);
	ft_putstr(str);
	free(flags);
	return (0);
}

int		ft_print_S(char *format, t_flags *flags, va_list ap)
{
	wchar_t		*str;
	(void)format;

	str = va_arg(ap, wchar_t *);
	(void)str;
	free(flags);
	return (0);
}

int		ft_print_p(char *format, t_flags *flags, va_list ap)
{
	void	*ptr;
	(void)format;

	ptr = va_arg(ap, void *);
	(void)ptr;
	free(flags);
	return (0);
}

int		ft_print_d(char *format, t_flags *flags, va_list ap)
{
	int		nb;
	(void)format;

	nb = va_arg(ap, int);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_D(char *format, t_flags *flags, va_list ap)
{
	long		nb;
	(void)format;

	nb = va_arg(ap, long);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_o(char *format, t_flags *flags, va_list ap)
{
	unsigned int		ret;
	unsigned int		nb;
	char				*to_print;
	(void)format;

	ret = 0;
	nb = va_arg(ap, unsigned int);
	to_print = ft_strdup(ft_convert_base(nb, 8));
	if (ft_has_flags(flags))
	{
		if (flags->sharp)
			to_print = ft_sharp_flag(UNS_OCTAL, ft_atoi(to_print));
	}
	ft_putstr(to_print);
	ret = ft_strlen(to_print);
	free(to_print);
	free(flags);
	return (ret);
}

int		ft_print_O(char *format, t_flags *flags, va_list ap)
{
	unsigned long		nb;
	(void)format;

	nb = va_arg(ap, unsigned long);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_u(char *format, t_flags *flags, va_list ap)
{
	unsigned int		nb;
	(void)format;

	nb = va_arg(ap, unsigned int);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_U(char *format, t_flags *flags, va_list ap)
{
	unsigned long		nb;
	(void)format;

	nb = va_arg(ap, unsigned long);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_x(char *format, t_flags *flags, va_list ap)
{
	unsigned int		nb;
	(void)format;

	nb = va_arg(ap, unsigned int);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_X(char *format, t_flags *flags, va_list ap)
{
	unsigned long		nb;
	(void)format;

	nb = va_arg(ap, unsigned long);
	ft_putnbr(nb);
	free(flags);
	return (0);
}

int		ft_print_c(char *format, t_flags *flags, va_list ap)
{
	unsigned int		nb;
	(void)format;

	nb = (unsigned int)va_arg(ap, int);
	ft_putchar(nb);
	free(flags);
	return (0);
}

int		ft_print_C(char *format, t_flags *flags, va_list ap)
{
	wint_t		nb;
	(void)format;

	nb = va_arg(ap, wint_t);
	ft_putchar(nb);
	free(flags);
	return (0);
}
