/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:26:10 by vlad              #+#    #+#             */
/*   Updated: 2017/03/25 20:54:28 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
	sSpdDioOuUxXcC
*/

int		identify_specifiers(t_string *rsrc, t_data *convert)
{
	char	ch;

	ch = *current_str(*rsrc, 0);
	if (ch == 's' || ch == 'S' || ch == 'p' || ch == 'd' || ch == 'D' || \
		ch == 'i' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' || \
		ch == 'x' || ch == 'X' || ch == 'c' || ch == 'C' || ch == '%')
	{
		convert->specifier = ch;
		rsrc->current_index++;
		return (OK);
	}
	else if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && ch)
	{
			convert->specifier = '&';
			rsrc->current_index++;
	}
	return (OK);
}
