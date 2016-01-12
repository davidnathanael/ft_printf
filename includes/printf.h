/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/12 15:32:09 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define TRUE 				1
# define FALSE 				0

# define STR 				's'
# define WSTR 				'S'
# define PTR	 			'p'
# define INT				'd'
# define LONG_INT			'D'
# define UNS_OCTAL			'o'
# define UNS_LONG_OCTAL		'O'
# define UNS_INT			'u'
# define UNS_LONG_INT		'U'
# define UNS_HEXA			'x'
# define UNS_LONG_HEXA		'X'
# define CHAR				'c'
# define WCHAR				'C'

# define SHARP				'#'
# define ZERO				'0'
# define MINUS				'-'
# define PLUS				'+'
# define SPACE				' '

# define L					1
# define LL					2
# define H					3
# define HH					4
# define J					5
# define Z					6

typedef	int			t_bool;
typedef	int			t_modifier;

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

t_flags				*ft_get_flags(char *format, int skip);
t_bool				ft_has_flags(t_flags *flags);
t_bool				ft_is_flag(char c);

t_bool				ft_skip(char *format);
t_bool				ft_is_modifier(char c);
int					ft_get_modifier(char *format);

#endif
