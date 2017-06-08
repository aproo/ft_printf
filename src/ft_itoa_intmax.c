/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 06:18:32 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 08:04:34 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_itoa_int_max(intmax_t value, int base)
{
	intmax_t	nbr;
	char		*result;
	char		*hex;
	int			i;

	nbr = value;
	hex = "0123456789abcdef";
	i = 0;
	if (value <= 0 && base == 10)
		i = 1;
	while (nbr != 0 && ++i > 0)
	{
		nbr /= base;
	}
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (value < 0 || value == 0)
		result[0] = (char)((value < 0) ? '-' : '0');
	result[i] = '\0';
	while (value)
	{
		result[--i] = hex[(value < 0) ? -(value % base) : (value % base)];
		value /= base;
	}
	return (result);
}
