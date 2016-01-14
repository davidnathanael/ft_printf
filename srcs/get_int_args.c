/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:16:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 12:35:58 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_get_int_args(t_options *options, va_list ap)
{
	unsigned long long	arg;
	t_type				type;
	(void)ap;

	arg = 0;
	type = options->type;
	if (type == T_INT)
		arg = va_arg(ap, int);
	if (type == T_UNS_INT)
		arg = va_arg(ap, unsigned int);
	if (type == T_LONG)
		arg = va_arg(ap, long);
	if (type == T_UNS_LONG)
		arg = va_arg(ap, unsigned long);
	if (type == T_LONG_LONG)
		arg = va_arg(ap, long long);
	if (type == T_UNS_LONG_LONG)
		arg = va_arg(ap, unsigned long long);
	ft_putnbr(arg);
	return (0);
}
