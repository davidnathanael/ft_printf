/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:04:02 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 08:30:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_proceed_signed_args(t_options *options, wchar_t *arg)
{
	int			ret;
	t_specifier	specifier;

	ret = 0;
	specifier = options->specifier;
	if (options->type == T_INT)
		ret = ft_proceed_int(options, (char *)arg);
	if (options->type == T_SHORT)
		ret = ft_proceed_short(options, (char *)arg);
	if (options->type == T_CHAR && options->specifier == CHAR)
		ret = ft_proceed_char(options, (char *)arg);
	if (options->type == T_CHAR && options->modifier == M_HH)
		ret = ft_proceed_signed_char(options, (char *)arg);
	else if (options->type == T_LONG)
		ret = ft_proceed_long(options, (char *)arg);
	else if (options->type == T_LONG_LONG)
		ret = ft_proceed_long_long(options, (char *)arg);
	else if (options->type == T_INTMAX_T)
		ret = ft_proceed_intmax_t(options, (char *)arg);
	return (ret);
}

int		ft_proceed_unsigned_args(t_options *options, wchar_t *arg)
{
	int			ret;

	ret = 0;
	if (options->type == T_UNS_INT)
		ret = ft_proceed_uns_int(options, (char *)arg);
	if (options->type == T_UNS_SHORT)
		ret = ft_proceed_uns_short(options, (char *)arg);
	if (options->type == T_UNS_CHAR && options->modifier == M_HH)
		ret = ft_proceed_signed_char(options, (char *)arg);
	if (options->type == T_UNS_LONG)
		ret = ft_proceed_uns_long(options, (char *)arg);
	else if (options->type == T_UNS_LONG_LONG)
		ret = ft_proceed_uns_long_long(options, (char *)arg);
	else if (options->type == T_SIZE_T)
		ret = ft_proceed_size_t(options, (char *)arg);
	else if (options->type == T_SSIZE_T)
		ret = ft_proceed_ssize_t(options, (char *)arg);
	return (ret);
}

int		ft_proceed_wide_args(t_options *options, wchar_t *arg)
{
	int			ret;

	ret = 0;
	if (options->type == T_WCHAR_T)
		ret = ft_proceed_wchar(options, arg);
	else if (options->type == T_WCHAR_T_PTR)
		ret = ft_proceed_wstr(options, arg);
	return (ret);
}

int		ft_proceed_ptr_args(t_options *options, wchar_t *arg)
{
	int			ret;

	ret = 0;
	if (options->type == T_CHAR_PTR)
		ret = ft_proceed_str(options, (char *)arg);
	else if (options->type == T_VOID_PTR)
		ret = ft_proceed_ptr(options, (char *)arg);
	else if (options->type == T_NOT_VALID_TYPE)
		ret = ft_proceed_not_valid_type(options, (char *)arg);
	return (ret);
}

int		ft_proceed(t_options *options, wchar_t *arg)
{
	int			ret;
	t_type		type;

	ret = 0;
	type = options->type;
	if (T_INT <= type && type <= T_INTMAX_T)
		ret = ft_proceed_signed_args(options, arg);
	else if (T_UNS_INT <= type && type <= T_SSIZE_T)
		ret = ft_proceed_unsigned_args(options, arg);
	else if (T_WINT_T <= type && type <= T_WCHAR_T_PTR)
		ret = ft_proceed_wide_args(options, arg);
	else if (T_CHAR_PTR <= type && type <= T_NOT_VALID_TYPE)
		ret = ft_proceed_ptr_args(options, arg);
	return (ret);
}
