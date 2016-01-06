/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/06 15:16:14 by ddela-cr         ###   ########.fr       */
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

typedef	int			t_type;

typedef struct		s_list
{
	char			*flags;
	int				precision;
	t_type			type;
	struct s_list	next;
}					t_list;

int			ft_printf(const char * restrict format, ...);

#endif
