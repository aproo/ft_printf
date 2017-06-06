/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:24:17 by vlad              #+#    #+#             */
/*   Updated: 2017/05/02 09:18:10 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - ?
*/

int		search_width(va_list *args, t_string *rsrc, t_data *convert)
{
	char	ch;
	size_t	i;

	ch = *current_str(*rsrc, 0);
	if (ch == '*')
	{
		convert->width = va_arg(*args, unsigned int);
		rsrc->current_index++;
		return (OK);
	}
	else if (ft_isdigit(ch))
	{
		convert->width = ft_atoi(rsrc->str + rsrc->current_index);
		i = convert->width;
		while (i)
		{
			i /= 10;
			rsrc->current_index++;
		}
	}
	return (OK);
}
