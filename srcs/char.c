/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:53:41 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 13:16:18 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "printf.h"
#include "libft.h"

size_t	ft_proceed_char(t_options *options, char *arg)
{
	size_t	ret;
	(void)options;
	ret = ft_putstr(arg);
	return (ret);
}
