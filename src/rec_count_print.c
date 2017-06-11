/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_count_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:18:50 by vmakahon          #+#    #+#             */
/*   Updated: 2017/06/11 05:19:10 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		rec_count_print(t_string *rsrc, void *ptr)
{
	int		*nb;

	nb = ptr;
	if (ptr)
		*nb = (int)rsrc->count_print;
}
