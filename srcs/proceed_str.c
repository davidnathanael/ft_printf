/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:13:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/20 00:29:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_str(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	ret = ft_putstr(arg);
	return (ret);
}

int		ft_proceed_char(t_options *options, char *arg)
{
	int		ret;

	ret = 0;
	char c = ft_atoi(arg);
	if (options->width > 0)
	{
		if (c != 0)
			ret = ft_putstr(arg);
		else
			ret = ft_putstr(ft_get_spaces(options->width));
		return (ret);
	}
	else
		ft_putchar(c);
	return (1);
}
