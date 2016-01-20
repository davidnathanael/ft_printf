/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:08:08 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/20 14:32:10 by ddela-cr         ###   ########.fr       */
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
	while (arg[i])
		len = (arg[i++] == ' ') ? len + 1 : len;
	len = (unsigned int)ft_strlen(arg) - len;
	i = 0;
	if ((int)len < (int)width)
	{
		while (arg[i])
		{
			if (arg[i] == ' ')
				arg[i] = '0';
			else if (arg[i] && arg[i] == '-' && ft_isdigit(arg[i + 1]))
			{
				arg[i] = '0';
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
				if (arg[0] == '0')
					arg[0] = ' ';
				else if (arg[0] != ' ')
					arg = ft_strjoin(" ", arg);
			}
		}
	return ((wchar_t *)arg);
}

wchar_t	*ft_apply_plus_flag(t_options *options, char *arg)
{
	unsigned int	i;
	(void)options;

	i = 0;
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
	{
		if (arg[0] == '0')
			arg[0] = '+';
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
	t_type		type;

	arg_tmp = arg;
	flags = options->flags;
	specifier = options->specifier;
	type = options->type;
	if (ft_has_flags(flags) && arg)
	{
		if (flags->sharp)
			arg = ft_apply_sharp_flag(specifier, (char *)arg);
		if (flags->zero)
			arg = ft_apply_zero_flag(options->width, (char *)arg);
		if (flags->space)
			arg = ft_apply_space_flag(specifier, (char *)arg);
		if (flags->plus 
			&& ((T_INT <= type && type <= T_SHORT) || type == T_INTMAX_T))
			arg = ft_apply_plus_flag(options, (char *)arg);
	}
	return (arg);
}
