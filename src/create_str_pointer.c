/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 09:25:06 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 09:27:23 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *set_precision_pointer(t_data *convert, char *result)
{
    char    *new;
//    char    *tmp;

    new = (char *)malloc(sizeof(char) * (convert->precision - (ft_strlen(result) - 2)));
    new[(convert->precision - (ft_strlen(result) - 2))] = '\0';
//    tmp = result;
    ft_memset(new, '0', (convert->precision - (ft_strlen(result) - 2)));
    result = ft_strjoin(new, result);
    result[1] = 'x';
    result[(ft_strlen(new) + 1)] = '0';
    free(new);
    return (result);
}

char			*create_str_pointer(t_data *convert, void *pointer)
{
	uintmax_t	nb;
	char 		*result;
	char 		*tmp;

	nb = (uintmax_t)pointer;
    if ((convert->set_precision) && !nb)
        result = ft_strdup("");
	else
        result = ft_itoa_uint_max(nb, 16);
    tmp = result;
    result = ft_strjoin("0x", tmp);
    if (convert->precision > ((int)ft_strlen(result) - 2))
        result = set_precision_pointer(convert, result);
    if ((int)convert->width > (convert->precision + 2))
	    result = set_width_str(convert, result);
//    free(tmp);
	return (result);
}

