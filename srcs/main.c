/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/11 09:18:11 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>

int	main()
{
	int a, b, c;
	a = 20;
	b = 1;
	c = 2;
	ft_printf("%s abc %d ok %s defgh %d testin %%\n", "esh", 2, "esh", 42);
	printf("%s abc %d ok %s defgh %d testin %%\n", "esh", 2, "esh", 42);
	return (0);
}
