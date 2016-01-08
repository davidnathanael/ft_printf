/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/08 16:41:48 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define INT		100
# define W_INT		110
# define UNS_INT	120
# define CHAR		200
# define W_CHAR		210
# define STR		300
# define PTR		400
# define OCT		500
# define HEX		600

# include <stdarg.h>

typedef	int			t_bool;

# define TRUE 1
# define FALSE 0

int			ft_printf(const char * restrict format, ...);
int			ft_do_format(char *format, va_list ap);

#endif
