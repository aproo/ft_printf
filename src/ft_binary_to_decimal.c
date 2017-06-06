/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:09:08 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:10:40 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - ?
*/

int				ft_binary_to_decimal(char *str)
{
	size_t		j;
	size_t		bit;
	int			result;

	j = 7;
	bit = 0;
	result = 0;
	while (bit < 8)
	{
		result += (str[bit++] - '0') * ft_int_power(2, j--);
	}
	return (result);
}
