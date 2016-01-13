/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 11:59:36 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>

int	main()
{
	ft_putstr("-------FT_PRINTF TESTS---------\n\n");

	ft_printf("abcdef %-23lc test % 4.08s ok %#0.0ld 42 %%");

/*
	ft_putstr("\n\n-------PRINTF TESTS---------\n\n");
	printf("%%o ->\t %o\n", 42);
	printf("%%#o ->\t %#o\n", 42);*/
	return (0);
}
