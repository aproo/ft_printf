/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 06:27:08 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:29:25 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - No?
*/

char		*ft_itoa_uint_max(uintmax_t value, int base)
{
	int			i;
	uintmax_t	nbr;
	char		*hex;
	char		*result;

	nbr = value;
	hex = "0123456789abcdef";
	i = 0;
	while (nbr != 0 && ++i > 0)
		nbr /= base;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (value == 0 && (i = 1) > 0)
		result[0] = '0';
	result[i] = '\0';
	while (value)
	{
		result[--i] = hex[value % base];
		value /= base;
	}
	return (result);
}
