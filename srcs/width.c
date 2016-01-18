/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:28:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/18 22:22:40 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int		ft_get_width(char *format)
{
	int		i;
	int		ret;
	char	*fmt;
	char	*tmp;

	i = 0;
	ret = -1;
	fmt = format;
	tmp = ft_strnew(ft_strlen(format));
	if (!tmp)
		return (ERR_STRNEW);
	while (!ft_isdigit(*fmt) && *fmt)
	{
		fmt++;
		if (*fmt == F_ZERO)
			fmt++;
		if (*fmt == '.')
			return (ret);
	}
	while (ft_isdigit(*fmt) && *fmt)
		tmp[i++] = *(fmt++);
	if (i > 0)
		ret = ft_atoi(tmp);
	free(tmp);
	return (ret);
}

static char	*ft_get_spaces(t_width width)
{
	char	*spaces;
	int		i;

	spaces = ft_strnew(width);
	i = 0;
	if (!spaces)
		return (NULL);
	while (i < width)
	{
		spaces[i] = ' ';
		i++;
	}
	return (spaces);
}

char	*ft_apply_width(t_options *options, char *arg)
{
	t_width	width;
	size_t	len;
	char	*ret;
	char	*spaces;

	width = options->width;
	len = ft_strlen(arg);
	ret = NULL;
	spaces = NULL;
	if (width)
	{
		spaces = ft_get_spaces(width - len);
		if (options->flags->minus)
			ret = ft_strjoin(arg, spaces);
		else
		{
			ret = ft_strjoin(spaces, arg);
		}
		if (!ret)
			return (NULL);
	}
	return (ret);
}
