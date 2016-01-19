/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 19:16:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/20 00:15:22 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_int(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_short(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_signed_char(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_int(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_short(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_uns_char(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_size_t(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_ssize_t(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	ret = ft_putstr(arg);
	return (ret);
}

