/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 12:37:10 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>

int	main()
{
	ft_putstr("-------FT_PRINTF TESTS---------\n\n");
	ft_printf("%d %d %d %d", 4, 95, 7, 3);
//	ft_printf("abcdef %-23lc test %#5.8X % 4.08s ok %#0.ld 42 %%");
/*
	ft_putstr("\n\n-------PRINTF TESTS---------\n\n");
	printf("%%o ->\t %o\n", 42);
	printf("%%#o ->\t %#o\n", 42);*/
	return (0);
}
