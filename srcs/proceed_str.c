/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:13:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 23:34:23 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <locale.h>
#include "printf.h"
#include "libft.h"

int		ft_proceed_str(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision_str(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_char(t_options *options, char *arg)
{
	int		ret;
	char	*arg_tmp;

	ret = 0;
	arg_tmp = ft_strnew(1);
	arg_tmp[0] = (unsigned char)ft_atoi(arg);
	if (options->precision >= 0)
		arg_tmp = ft_apply_precision_str(options, arg_tmp);
	if (options->width > 0)
		arg_tmp = ft_apply_width(options, arg_tmp);
	if (ft_has_flags(options->flags))
		arg_tmp = (char *)ft_apply_flags(options, (wchar_t *)arg_tmp);
	if (ft_atoi(arg) == 0)
	{
		ret = ft_putstr(arg_tmp);
		ft_putchar((unsigned char)ft_atoi(arg));
		ret++;
	}
	else
		ret = ft_putstr(arg_tmp);
	return (ret);
}
