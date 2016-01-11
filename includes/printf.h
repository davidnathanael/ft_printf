/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/11 12:02:59 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

typedef	int			t_bool;

# define TRUE 1
# define FALSE 0

# define	STR 			s
# define	WSTR 			S
# define	PTR	 			p
# define	INT				d
# define	LONG_INT		D
# define	OCTAL			o
# define	UNS_OCTAL		O
# define	UNS_INT			u
# define	UNS_LONG_INT	U
# define	HEXA			x
# define	UNS_HEXA		X
# define	CHAR			c
# define	WCHAR			C

int			ft_printf(const char * restrict format, ...);
int			ft_do_format(char *format, va_list ap);

int			ft_print_s(char *format, va_list ap);
int			ft_print_S(char *format, va_list ap);
int			ft_print_p(char *format, va_list ap);
int			ft_print_d(char *format, va_list ap);
int			ft_print_D(char *format, va_list ap);
int			ft_print_o(char *format, va_list ap);
int			ft_print_O(char *format, va_list ap);
int			ft_print_u(char *format, va_list ap);
int			ft_print_U(char *format, va_list ap);
int			ft_print_x(char *format, va_list ap);
int			ft_print_X(char *format, va_list ap);
int			ft_print_c(char *format, va_list ap);
int			ft_print_C(char *format, va_list ap);

#endif
