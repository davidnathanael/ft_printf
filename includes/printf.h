/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 11:27:44 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define TRUE 1
# define FALSE 0

# define	STR 			's'
# define	WSTR 			'S'
# define	PTR	 			'p'
# define	INT				'd'
# define	LONG_INT		'D'
# define	UNS_OCTAL		'o'
# define	UNS_LONG_OCTAL	'O'
# define	UNS_INT			'u'
# define	UNS_LONG_INT	'U'
# define	UNS_HEXA		'x'
# define	UNS_LONG_HEXA	'X'
# define	CHAR			'c'
# define	WCHAR			'C'

# define	SHARP			'#'
# define	ZERO			'0'
# define	MINUS			'-'
# define	PLUS			'+'
# define	SPACE			' '

typedef	int			t_bool;

typedef struct		s_flags
{
	t_bool			sharp;
	t_bool			zero;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
}					t_flags;

int					ft_printf(const char *restrict format, ...);
int					ft_do_format(char *format, va_list ap);

int					ft_print_s(char *format, t_flags *flags, va_list ap);
int					ft_print_S(char *format, t_flags *flags, va_list ap);
int					ft_print_p(char *format, t_flags *flags, va_list ap);
int					ft_print_d(char *format, t_flags *flags, va_list ap);
int					ft_print_D(char *format, t_flags *flags, va_list ap);
int					ft_print_o(char *format, t_flags *flags, va_list ap);
int					ft_print_O(char *format, t_flags *flags, va_list ap);
int					ft_print_u(char *format, t_flags *flags, va_list ap);
int					ft_print_U(char *format, t_flags *flags, va_list ap);
int					ft_print_x(char *format, t_flags *flags, va_list ap);
int					ft_print_X(char *format, t_flags *flags, va_list ap);
int					ft_print_c(char *format, t_flags *flags, va_list ap);
int					ft_print_C(char *format, t_flags *flags, va_list ap);

t_flags				*ft_get_flags(char *format, int skip);
t_bool				ft_has_flags(t_flags *flags);
t_bool				ft_is_flag(char c);
char				*ft_sharp_flag(char type, int nb);

t_bool				ft_is_modifier(char c);
#endif
