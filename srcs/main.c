/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/22 15:54:31 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>
#include <stdint.h>
#include <limits.h>
#include <locale.h>

int	main()
{
	/*
	   ft_putstr("-------FT_PRINTF TESTS---------\n\n");
	   int ret1 = printf("{%30S}", L"我是一只猫。");
	   ft_putstr("\nret1l : ");
	   ft_putnbr(ret1);
	   ft_putstr("\n");
	   */
	char	*l = setlocale(LC_ALL, "");

	if (l == NULL)
		printf("Locale not set\n");
	else
		printf("Locale set to %s\n", l);
	ft_putnbr(ft_printf("%4.15S", L"我是一只猫。"));
	return (0);
}
