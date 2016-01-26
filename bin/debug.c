/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:08:42 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 15:56:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_print_options(t_options *options, char *format)
{
	printf("\n--------------------------------------\n");
	printf("\n\n------- FORMAT ---------\n");
	printf(" -> format |%s|", format);

	printf("\n------- FLAGS ----------\n");
	printf(" -> sharp : %d\n", options->flags->sharp);
	printf(" -> zero : %d\n", options->flags->zero);
	printf(" -> minus : %d\n", options->flags->minus);
	printf(" -> plus : %d\n", options->flags->plus);
	printf(" -> space : %d\n", options->flags->space);

	printf("\n------- WIDTH ----------\n");
	printf(" -> width : %d\n", options->width);

	printf("\n------- PRECISION ------\n");
	printf(" -> precision : %d\n", options->precision);

	printf("\n------- MODIFIER -------\n");
	printf(" -> modifier : %d\n", options->modifier);

	printf("\n------- SPECIFIER ------\n");
	printf(" -> specifier : %c\n", options->specifier);

	printf("\n------- TYPE ----------\n");
	printf(" -> type : %d\n", options->type);
	printf("\n--------------------------------------\n");
}
