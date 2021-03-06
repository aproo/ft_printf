/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:11:18 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:28:23 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - ?
*/

int			ft_int_power(int nb, int power)
{
	int		result;

	if (power == 0)
		result = 1;
	else
		result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}
