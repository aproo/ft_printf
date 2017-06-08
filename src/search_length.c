/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:25:18 by vlad              #+#    #+#             */
/*   Updated: 2017/04/03 05:24:37 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	norm - OK; leaks - OK;
*/

int			search_length(t_string *rsrc, t_data *convert)
{
	char	ch;
	char	ch_next;

	ch = *current_str(*rsrc, 0);
	ch_next = *current_str(*rsrc, 1);
	if (ch == 'h' && ch_next == 'h')
		convert->lenght = HH;
	else if (ch == 'h')
		convert->lenght = H;
	else if (ch == 'l' && ch_next == 'l')
		convert->lenght = LL;
	else if (ch == 'l')
		convert->lenght = L;
	else if (ch == 'j')
		convert->lenght = J;
	else if (ch == 'z')
		convert->lenght = Z;
	else
		return (OK);
	rsrc->current_index += (convert->lenght == LL ||
			convert->lenght == HH) ? 2 : 1;
	return (OK);
}
