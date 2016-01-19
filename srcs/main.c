/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 13:23:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>
#include <stdint.h>
#include <limits.h>

int	main()
{
	ft_putstr("-------FT_PRINTF TESTS---------\n\n");
	int ret1 = ft_printf("{%10d}\n", 42);
	int ret2 = printf("{%10d}\n", 42);
	ft_putnbr(ret1);
	ft_putstr("|");
	ft_putnbr(ret2);
	return (0);
}
