/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:39:17 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:32:33 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Norm - OK, leaks - OK		sSpdDioOuUxXcC
*/

void		add_fix_main(t_string *rsrc, t_data *convert)
{
	char	sp;

	(void)rsrc;
	sp = convert->specifier;
	if (convert->flags.fill_zeros && (convert->flags.left_justify))
		convert->flags.fill_zeros = 0;
	if (convert->flags.space && (convert->specifier == 'u' ||
				convert->specifier == 'U'))
		convert->flags.space = 0;
	if (sp == 'S' || sp == 'D' || sp == 'O' || sp == 'U' || sp == 'C')
		convert->lenght = L;
	if (sp == 'p' && (convert->precision || convert->set_precision))
		convert->flags.fill_zeros = 0;
	if (convert->precision < 0)
	{
		convert->precision = 0;
		convert->set_precision = 0;
	}
	if (convert->width < 0)
	{
		convert->width = -convert->width;
		convert->flags.left_justify = 1;
	}
}
