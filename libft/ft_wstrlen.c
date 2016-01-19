/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:52:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 18:56:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenwstr(wchar_t *str)
{
	int		result;

	result = 0;
	while (*str)
		result += ft_wcharlen(*str++);
	return (result);
}
