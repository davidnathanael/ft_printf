/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:14:57 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 16:24:27 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "printf.h"

t_type		ft_apply_l_modifier(t_specifier specifier);
t_type		ft_apply_ll_modifier(t_specifier specifier);
t_type		ft_apply_h_modifier(t_specifier specifier);
t_type		ft_apply_hh_modifier(t_specifier specifier);
t_type		ft_apply_j_modifier(t_specifier specifier);
t_type		ft_apply_z_modifier(t_specifier specifier);

t_bool		ft_is_modifier(char c)
{
	if (c == 'l')
		return (TRUE);
	if (c == 'h')
		return (TRUE);
	if (c == 'j')
		return (TRUE);
	if (c == 'z')
		return (TRUE);
	return (FALSE);
}

int		ft_get_modifier(char *format)
{
	t_modifier	modifier;

	modifier = NO_MODIFIER;
	if (ft_strstr(format, "ll"))
			modifier = M_LL;
	else if (ft_strchr(format, 'l'))
			modifier = M_L;
	else if (ft_strstr(format, "hh"))
			modifier = M_HH;
	else if (ft_strchr(format, 'h'))
			modifier = M_H;
	else if (ft_strchr(format, 'j'))
			modifier = M_J;
	else if (ft_strchr(format, 'z'))
			modifier = M_Z;
	return (modifier);
}

t_type		ft_set_type(t_specifier specifier)
{
	if (specifier == STR)
		return (T_CHAR_PTR);
	if (specifier == WSTR)
		return (T_WCHAR_T_PTR);
	if (specifier == PTR)
		return (T_VOID_PTR);
	if (specifier == INT || specifier == I_INT)
		return (T_INT);
	if (specifier == LONG)
		return (T_LONG);
	if (ft_strchr("ouxX", specifier))
		return (T_UNS_INT);
	if (specifier == UNS_LONG_OCTAL || specifier == UNS_LONG)
		return (T_UNS_LONG);
	if (specifier == CHAR)
		return (T_CHAR);
	if (specifier == WCHAR)
		return (T_WCHAR_T);
	return (ERROR);
}

t_options	*ft_apply_modifier(t_options *options)
{
	t_specifier		specifier;
	t_modifier		modifier;

	specifier = options->specifier;
	modifier = options->modifier;
	if (modifier == NO_MODIFIER)
		options->type = ft_set_type(specifier);
	else if (modifier == M_L)
		options->type = ft_apply_l_modifier(specifier);
	else if (modifier == M_LL)
		options->type = ft_apply_ll_modifier(specifier);
	else if (modifier == M_H)
		options->type = ft_apply_h_modifier(specifier);
	else if (modifier == M_HH)
		options->type = ft_apply_hh_modifier(specifier);
	else if (modifier == M_J)
		options->type = ft_apply_j_modifier(specifier);
	else if (modifier == M_Z)
		options->type = ft_apply_z_modifier(specifier);
	return (options);
}

t_type		ft_apply_l_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_LONG;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UNS_LONG;
	if (specifier == CHAR)
		type = T_WINT_T;
	if (specifier == STR)
		type = T_WCHAR_T_PTR;
	return (type);
}

t_type		ft_apply_ll_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_LONG_LONG;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
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
	if (specifier == UNS_OCTAL || specifier == UNS_INT
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
	return (type);
}

t_type		ft_apply_j_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_INTMAX_T;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_UINTMAX_T;
	return (type);
}

t_type		ft_apply_z_modifier(t_specifier specifier)
{
	t_type		type;

	type = NO_TYPE;
	if (specifier == INT || specifier == I_INT)
		type = T_SIZE_T;
	if (specifier == UNS_OCTAL || specifier == UNS_INT
		|| specifier == UNS_HEXA || specifier == UNS_HEXA_MAJ)
		type = T_SIZE_T;
	return (type);
}
