/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:11:59 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 21:31:38 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "printf.h"
#include "libft.h"

static wchar_t	*ft_get_void_ptr(va_list ap)
{
	char		*ret;
	char		*to_prepend;
	unsigned long	arg;

	ret = NULL;
	to_prepend = ft_strdup("0x");
	arg = va_arg(ap, unsigned long);
	ret = ft_strjoin(to_prepend, ft_itoa_base(arg, "0123456789abcdef"));
	return ((wchar_t *)ret);
}

wchar_t		*ft_get_ptr_arg(t_options *options, va_list ap)
{
	wchar_t		*arg;
	t_type	type;

	arg = NULL;
	type = options->type;
	if (type == T_WCHAR_T_PTR)
		arg = va_arg(ap, wchar_t *);
	else if (type == T_CHAR_PTR)
		arg = (wchar_t *)ft_strdup(va_arg(ap, char *));
	else if (type == T_VOID_PTR)
		arg = ft_get_void_ptr(ap);
	return (arg);
}

wchar_t		*ft_get_wint_arg(t_options *options, va_list ap)
{
	wchar_t		*arg;
	t_type		type;

	arg = (wchar_t *)ft_strnew(sizeof(wchar_t));
	type = options->type;
	arg[0] = va_arg(ap, wchar_t);
	return (arg);
}
