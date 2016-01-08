/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:54:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/06 15:58:46 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*ft_set_flags(char *format, va_list ap, int index)
{
	char	*str;
	int		i;

	i = 0;
	while (i <= index)
	{
		while (i < index)
		{
			str = ft_strchr(format, '%');
			while (str[1] == '%' && str[1])
				str++;
		}
		str = ft_strchr(format, '%');
		while (str[1] == '%' && str[1])
			str++;
		
		i++;
	}
}

static t_list	*ft_create_list(char *format, va_list ap)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->flags = ft_set_flags(format, ap, 0);
	return (list);
}

t_list			*ft_set_list(const char *format, va_list ap, int nb_params)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < nb_params)
	{
		ft_list_append(format, va_list ap, i);
		i++;
	}
}
