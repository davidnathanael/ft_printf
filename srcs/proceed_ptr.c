/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:27:49 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/20 16:19:48 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_ptr(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (options->precision >= 0)
		arg = ft_apply_precision_ptr(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_not_valid_type(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

char		*ft_apply_precision_ptr(t_options *options, char *arg)
{
	char 	*ret;

	ret = NULL;
	if (ft_strlen(ft_strtrim((char *)arg)) > (size_t)options->precision)
		return (ret = ft_strsub(arg, 0, (size_t)options->precision));
	return (arg);
}
