/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:27:49 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/25 09:59:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int		ft_proceed_ptr(t_options *options, char *arg)
{
	int				ret;
	unsigned long	atoi;

	ret = 0;
	atoi = ft_atoi_uns_long(arg);
	if (options->precision >= 0)
		arg = ft_apply_precision_ptr(options, arg, atoi);
	else
		arg = ft_strjoin("0x", ft_itoa_base(atoi, "0123456789abcdef"));
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_not_valid_type(t_options *options, char *arg)
{
	int	ret;

	ret = 0;
	if (options->width > 0)
		arg = ft_apply_width(options, arg);
	if (ft_has_flags(options->flags))
		arg = (char *)ft_apply_flags(options, (wchar_t *)arg);
	ret = ft_putstr(arg);
	return (ret);
}

char	*ft_get_zero(int len)
{
	char	*ret;

	ret = ft_strnew((size_t)len);
	if (!ret)
		return (NULL);
	while (len)
		ret[--len] = '0';
	return (ret);
}

char	*ft_apply_precision_ptr(t_options *options, char *arg,
									unsigned long atoi)
{
	char	*ret;
	char	*zero;

	ret = NULL;
	zero = NULL;
	if (atoi == 0)
	{
		if (options->precision == 0)
			return (ft_strdup("0x"));
		else if (options->precision > 0)
			ret = ft_get_zero(options->precision);
	}
	else
	{
		arg = ft_itoa_base(atoi, "0123456789abcdef");
		if ((int)ft_strlen(arg) < options->precision)
			ret = ft_strjoin(ft_get_zero(options->precision - \
								ft_strlen(arg)), arg);
		else
			ret = ft_strdup(arg);
	}
	free(arg);
	return (ft_strjoin("0x", ret));
}
