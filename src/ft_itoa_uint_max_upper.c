/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint_max_upper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:42:25 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/07 15:44:44 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		    *ft_itoa_uint_max_upper(uintmax_t value, int base)
{
    int			i;
    uintmax_t	nbr;
    char		*hex;
    char		*result;

    nbr = value;
    hex = "0123456789ABCDEF";
    i = (nbr == 0) ? 1 : 0;
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
