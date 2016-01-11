/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:19:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/11 12:46:36 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdio.h>
#include <libft.h>

int	main()
{
	int a, b, c;
	a = 0;
	b = 0;
	c = 2;
	ft_printf("ft_printf : %s abc %c ok %s defgh %d testin %%\n", "esh", 'a', "esh", 42);
	printf("printf : %s abc %d ok %s defgh %d testin %%\n", "esh", 2, "esh", 42);
	return (0);
}
