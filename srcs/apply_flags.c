/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:08:08 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 13:09:12 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

wchar_t	*ft_apply_sharp_flag(t_specifier specifier, char *arg)
{
	char	*ret;
	t_bool	is_null;

	ret = NULL;
	is_null = FALSE;
	if (arg[0] == '0' && ft_isdigit(arg[1]) == FALSE)
		is_null = TRUE;
	if ((specifier == UNS_OCTAL || specifier == UNS_LONG_OCTAL)
			&& ft_atoi(arg) != 0)
	{
			ret = ft_strjoin("0", (char *)arg);
	}
	else if (specifier == UNS_HEXA && !is_null)
		ret = ft_strjoin("0x", arg);
	else if (specifier == UNS_HEXA_MAJ && !is_null)
		ret = ft_strjoin("0X", arg);
	else
		ret = ft_strdup("0");
	return ((wchar_t *)ret);
}

wchar_t	*ft_apply_zero_flag(t_width width, char *arg)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (arg[i] == ' ' && arg[i])
		i++;
	len = (unsigned int)ft_strlen(arg) - i;
	i = 0;
	if ((int)len < (int)width)
	{
		while (arg[i])
		{
			if (arg[i] == ' ')
				arg[i] = '0';
			else if (arg[i] && ft_isdigit(arg[i]) && arg[i - 1] == '-')
			{
				arg[i - 1] = '0';
				arg[0] = '-';
			}
			i++;
		}
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_space_flag(t_specifier specifier, char *arg)
{
	if (arg[0] != '-')
	{
		if (specifier == INT || specifier == I_INT)
		{
			if (arg[0] != ' ')
				arg = ft_strjoin(" ", arg);
		}
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_plus_flag(t_type type, char *arg)
{
	unsigned int	i;

	i = 0;
	if ((T_INT <= type && type <= T_SHORT) || type == T_INTMAX_T)
	{
		if ((!ft_isdigit(arg[0])) && arg[0])
		{
			while (arg[i])
			{
				if (arg[i] == '-')
					break ;
				if (ft_isdigit(arg[i]))
					arg[i - 1] = '+';
				i++;
			}
		}
		else
			arg = ft_strjoin("+", arg);
	}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_flags(t_options *options, wchar_t *arg)
{
	wchar_t		*arg_tmp;
	t_flags		*flags;
	t_specifier	specifier;

	arg_tmp = arg;
	flags = options->flags;
	specifier = options->specifier;
	if (ft_has_flags(flags))
	{
		if (flags->sharp)
			arg = ft_apply_sharp_flag(specifier, (char *)arg);
		if (flags->zero)
			arg = ft_apply_zero_flag(options->width, (char *)arg);
		if (flags->space)
			arg = ft_apply_space_flag(specifier, (char *)arg);
		if (flags->plus)
			arg = ft_apply_plus_flag(options->type, (char *)arg);
	}
	return (arg);
}
