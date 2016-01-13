/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:16:24 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 12:44:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_int_args(t_options options, va_list ap)
{
	unsigned long long	arg;
	t_type				type;

	arg = 0;
	type = options->type;
	if (type == INT)
		arg = va_arg(ap, int);
	if (type == LONG)
		arg = va_arg(ap, long);
	if (type == UNS_INT || type == UNS_OCTAL || type == UNS_HEXA)
		arg = va_arg(ap, unsigned int);
	if (type == UNS_LONG || type == UNS_LONG_OCTAL || type == UNS_LONG_HEXA)
		arg = va_arg(ap, unsigned long);
}
