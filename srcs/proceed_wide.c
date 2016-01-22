/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_wide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:07:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 12:21:54 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

wchar_t		*ft_apply_precision_wstr(t_options *options, wchar_t *arg);
wchar_t		*ft_apply_width_wstr(t_options *options, wchar_t *arg);

int			ft_proceed_wchar(t_options *options, wchar_t *arg)
{
	(void)options;
	int		ret;

	ret = ft_putwchar(arg[0]);
	return (ret);
}

int			ft_proceed_wstr(t_options *options, wchar_t *arg)
{
	(void)options;
	int		ret;

	if (options->precision >= 0)
		arg = ft_apply_precision_wstr(options, arg);
	if (options->width > 0)
		arg = ft_apply_width_wstr(options, arg);
	if (ft_has_flags(options->flags))
		arg = ft_apply_flags(options, arg);
	ret = ft_putwstr(arg);
	return (ret);
}

static wchar_t		*ft_get_zero_wstr(int len)
{
	wchar_t	*ret;

	ret = ft_memalloc(len * sizeof(wchar_t) + 1);
	if (!ret)
		return (NULL);
	while (len)
		ret[--len] = '0';
	return (ret);
}

wchar_t		*ft_apply_precision_wstr(t_options *options, wchar_t *arg)
{
	wchar_t 	*ret;

	ret = NULL;
	if (!arg)
		ret = ft_get_zero_wstr(options->precision);
	else
	{
		ret = ft_memalloc(options->precision + 1);
		ret[options->precision] = '\0';
		if (ft_strlen(ft_strtrim((char *)arg)) > (size_t)options->precision)
			ret = ft_memmove(ret, arg, options->precision);
		else
			ret = ft_memcpy(ret, arg, options->precision);
	}
	return (ret);
}

wchar_t		*ft_get_spaces_wstr(t_width width)
{
	wchar_t	*spaces;
	int		i;

	spaces = ft_memalloc(sizeof(wchar_t) * width + 1);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	return (spaces);
}

wchar_t		*ft_apply_width_wstr(t_options *options, wchar_t *arg)
{
	t_width	width;
	int		len;
	wchar_t	*ret;
	wchar_t	*spaces;

	width = options->width;
	len = ft_wstrlen(arg);
	ret = NULL;
	spaces = NULL;
	if (width > (int)len)
	{
		spaces = ft_get_spaces_wstr(width - len);
		if (options->flags->minus 
			|| (options->type == T_VOID_PTR && options->flags->zero))
			ret = ft_wstrjoin(arg, spaces);
		else
			ret = ft_wstrjoin(spaces, arg);
		if (!ret)
			return (NULL);
	}
	else
		return (arg);
	return (ret);
}
