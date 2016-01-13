/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/13 11:31:09 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define TRUE 				1
# define FALSE 				0

# define ERR_STRNEW			-2

# define NO_WIDTH			-1
# define NO_PRECI			-1

# define STR 				's'
# define WSTR 				'S'
# define PTR	 			'p'
# define INT				'd'
# define LONG				'D'
# define UNS_OCTAL			'o'
# define UNS_LONG_OCTAL		'O'
# define UNS_INT			'u'
# define UNS_LONG			'U'
# define UNS_HEXA			'x'
# define UNS_LONG_HEXA		'X'
# define CHAR				'c'
# define WCHAR				'C'

# define F_SHARP			'#'
# define F_ZERO				'0'
# define F_MINUS			'-'
# define F_PLUS				'+'
# define F_SPACE			' '

# define M_L				1
# define M_LL				2
# define M_H				3
# define M_HH				4
# define M_J				5
# define M_Z				6

typedef	int			t_bool;

typedef	int			t_width;
typedef	int			t_precision;
typedef	int			t_modifier;
typedef	char		t_type;

typedef struct		s_flags
{
	t_bool			sharp;
	t_bool			zero;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
}					t_flags;

typedef struct		s_options
{
	t_flags			*flags;
	t_width			width;
	t_precision		precision;
	t_modifier		modifier;
	t_type			type;
}					t_options;

int					ft_printf(const char *restrict format, ...);
int					ft_do_format(char *format, va_list ap);

t_flags				*ft_get_flags(char *format);
t_bool				ft_has_flags(t_flags *flags);
t_bool				ft_is_flag(char c);

t_bool				ft_skip(char *format);
t_bool				ft_is_modifier(char c);
int					ft_get_modifier(char *format);
int					ft_get_width(char *format);
int					ft_get_precision(char *format);

//DEBUG
void	ft_print_options(t_options *options, char *format);

#endif
