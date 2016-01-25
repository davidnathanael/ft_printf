/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lh_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:43:33 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/25 09:49:14 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_type		ft_apply_l_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT || specifier == LONG)
		type = T_LONG;
	if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
			|| specifier == UNS_INT || specifier == UNS_LONG
			|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UNS_LONG;
	if (specifier == CHAR)
		type = T_WCHAR_T;
	if (specifier == STR)
		type = T_WCHAR_T_PTR;
	if (specifier == PTR)
		type = T_VOID_PTR;
	return (type);
}

t_type		ft_apply_ll_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT
		|| specifier == LONG)
		type = T_LONG_LONG;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_LONG_OCTAL || specifier == UNS_LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UNS_LONG_LONG;
	return (type);
}

t_type		ft_apply_h_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_SHORT;
	if (specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL
		|| specifier == UNS_INT || specifier == UNS_LONG || specifier == LONG
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UNS_SHORT;
	return (type);
}

t_type		ft_apply_hh_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_CHAR;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UNS_CHAR;
	if (specifier == UNS_LONG_OCTAL || specifier == UNS_LONG
		|| specifier == LONG)
		type = T_UNS_SHORT;
	return (type);
}