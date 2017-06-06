/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_szero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:59:54 by vmakahon          #+#    #+#             */
/*   Updated: 2017/03/25 20:04:26 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_szero(t_string *rsrc, t_data *convert, t_flags *flags)
{
	if (rsrc)
	{
		rsrc->current_index = 0;
		rsrc->count_print = 0;
		rsrc->error = 0;
		rsrc->str = NULL;
	}
	if (convert)
	{
		convert->width = 0;
		convert->precision = 0;
		convert->lenght = 0;
		convert->set_precision = 0;
	}
	if (flags)
	{
		flags->left_justify = 0;;
		flags->sign = 0;
		flags->space = 0;
		flags->fill_zeros = 0;
		flags->hashtag = 0;
	}
}
