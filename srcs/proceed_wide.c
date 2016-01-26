/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_wide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:07:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/26 23:34:22 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int			ft_proceed_wchar(t_options *options, wchar_t *arg)
{
	int		ret;

	(void)options;
	ret = ft_putwchar(arg[0]);
	return (ret);
}

int			ft_proceed_wstr(t_options *options, wchar_t *arg)
{
	int		ret;

	ret = 0;
	if (options->precision >= 0)
		arg = ft_apply_precision_wstr(options, arg);
	if (options->width > 0)
		arg = ft_apply_width_wstr(options, arg);
	if (ft_has_flags(options->flags))
		arg = ft_apply_flags(options, arg);
	ret = ft_putwstr(arg);
	return (ret);
}
