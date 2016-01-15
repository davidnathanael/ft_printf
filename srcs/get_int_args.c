/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:16:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/15 00:17:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "printf.h"
#include "libft.h"

char	*ft_get_signed_args(t_options *options, va_list ap)
{
	intmax_t			arg;
	t_type				type;
	char				*ret;

	arg = 0;
	type = options->type;
	ret = NULL;
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
	ret = ft_itoa_long_long(arg);
	return (ret);
}

char	*ft_get_unsigned_args(t_options *options, va_list ap)
{
	uintmax_t			arg;
	t_type				type;
	char				*ret;

	arg = 0;
	type = options->type;
	ret = NULL;
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
	ret = ft_itoa_long_long(arg);
	return (ret);
}
