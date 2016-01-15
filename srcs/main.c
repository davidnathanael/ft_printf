/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/15 12:37:52 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>
#include <stdint.h>

int	main()
{
	size_t	a = 42;
	char *s = strdup("test");
	ft_putstr("-------FT_PRINTF TESTS---------\n\n");
	ft_printf("%p %u %o %.10jd %c %zd\n", (void *)s, 95, 7, (intmax_t)-922337, 'A', a);
	printf("%p %u %o %.10jd %c %zd\n", (void *)s, 95, 7, (intmax_t)-922337, 'A', a);
/*
	ft_putstr("\n\n-------PRINTF TESTS---------\n\n");
	printf("%%o ->\t %o\n", 42);
	printf("%%#o ->\t %#o\n", 42);*/
	return (0);
}
