/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 00:56:04 by ddela-cr         ###   ########.fr       */
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
	int ret1 = printf("{%c}", 0);
	ft_putstr("\nret1 : ");
	ft_putnbr(ret1);
	ft_putstr("\n");

	return (0);
}
