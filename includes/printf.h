/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/14 16:24:52 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
#include <inttypes.h>

# define TRUE				1
# define FALSE				0

# define ERROR				-1
# define ERR_STRNEW			-2

# define NO_WIDTH			-1
# define NO_PRECI			-1

# define STR				's'
# define WSTR				'S'
# define PTR				'p'
# define INT				'd'
# define I_INT				'i'
# define LONG				'D'
# define UNS_OCTAL			'o'
# define UNS_LONG_OCTAL		'O'
# define UNS_INT			'u'
# define UNS_LONG			'U'
# define UNS_HEXA			'x'
# define UNS_HEXA_MAJ		'X'
# define CHAR				'c'
# define WCHAR				'C'

# define F_SHARP			'#'
# define F_ZERO				'0'
# define F_MINUS			'-'
# define F_PLUS				'+'
# define F_SPACE			' '

typedef	int			t_bool;

typedef	int			t_width;
typedef	int			t_precision;
typedef	int			t_specifier;

typedef enum e_type
{
	NO_TYPE,
	T_INT,
	T_LONG,
	T_LONG_LONG,
	T_SHORT,
	T_CHAR,
	T_INTMAX_T,
	T_UNS_INT,
	T_UNS_LONG,
	T_UNS_LONG_LONG,
	T_UNS_SHORT,
	T_UNS_CHAR,
	T_UINTMAX_T,
	T_SIZE_T,
	T_WINT_T,
	T_WCHAR_T,
	T_WCHAR_T_PTR,
	T_CHAR_PTR,
	T_VOID_PTR,
}			t_type;

typedef enum		e_modifier
{
	NO_MODIFIER,
	M_L,
	M_LL,
	M_H,
	M_HH,
	M_J,
	M_Z,
}					t_modifier;

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
	t_specifier		specifier;
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

t_options			*ft_apply_modifier(t_options *options);
intmax_t			ft_get_signed_args(t_options *options, va_list ap);
uintmax_t			ft_get_unsigned_args(t_options *options, va_list ap);

//DEBUG
void				ft_print_options(t_options *options, char *format);

#endif
