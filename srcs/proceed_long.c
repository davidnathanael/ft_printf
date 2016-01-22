/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 22:02:10 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 07:50:47 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_long_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_intmax_t(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_long_long(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uintmax_t(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision(options, arg);
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}
