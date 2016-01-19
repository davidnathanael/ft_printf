/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:27:49 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 21:29:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_proceed_ptr(t_options *options, char *arg)
{
	int 	ret;
	(void)options;

	ret = 0;
	ret = ft_putstr(arg);
	return (ret);
}
