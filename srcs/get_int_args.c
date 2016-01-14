/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:16:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 16:18:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "printf.h"
#include "libft.h"

intmax_t ft_get_signed_args(t_options *options, va_list ap)
{
	intmax_t			arg;
	t_type				type;

	arg = 0;
	type = options->type;
	if (type == T_INT)
		arg = va_arg(ap, int);
	if (type == T_LONG)
		arg = va_arg(ap, long);
	if (type == T_LONG_LONG)
		arg = va_arg(ap, long long);
	if (type == T_SHORT)
		arg = va_arg(ap, int);
	if (type == T_CHAR)
		arg = va_arg(ap, int);
	if (type == T_INTMAX_T)
		arg = va_arg(ap, intmax_t);
	ft_putstr(ft_itoa_long_long(arg));
	return (0);
}

uintmax_t ft_get_unsigned_args(t_options *options, va_list ap)
{
	uintmax_t			arg;
	t_type				type;

	arg = 0;
	type = options->type;
	if (type == T_UNS_INT)
		arg = va_arg(ap, unsigned int);
	if (type == T_UNS_LONG)
		arg = va_arg(ap, unsigned long);
	if (type == T_UNS_LONG_LONG)
		arg = va_arg(ap, unsigned long long);
	if (type == T_UNS_SHORT)
		arg = va_arg(ap, int);
	if (type == T_UNS_CHAR)
		arg = va_arg(ap, int);
	if (type == T_UINTMAX_T)
		arg = va_arg(ap, uintmax_t);
	if (type == T_SIZE_T)
		arg = va_arg(ap, size_t);
	ft_putstr(ft_itoa_long_long(arg));
	return (0);
}
