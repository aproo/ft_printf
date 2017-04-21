/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:05:24 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/07 09:07:42 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/ft_printf.h"

//no leaks

static int spec_is_numbers(char ch)
{
    return ((ch == 'd' || ch == 'D' || ch == 'i' || ch == 'o' ||
             ch == 'O' || ch == 'u' || ch == 'U' || ch == 'x' ||
             ch == 'X') ? 1 : 0);
}


void        check_width_numbers(t_data *convert, char **str, int width, int sign)
{
    char    *tmp;
    char    *new;

    tmp = *str;
    new = ft_strnew(width);
    if ((convert->flags.fill_zeros && !convert->precision &&
            !convert->set_precision) || (convert->specifier == '%' &&
            !convert->flags.left_justify && convert->flags.fill_zeros))
        ft_memset(new, '0', width);
    else
        ft_memset(new, ' ', width);

    if (convert->flags.left_justify)
        *str = ft_strjoin(tmp, new);
    else
        *str = ft_strjoin(new, tmp);
    if (sign > 0 && convert->flags.fill_zeros)
    {
        str[0][((sign == 1) ? 0 : 1)] = ((sign == 1) ? tmp[0] : tmp[1]);
        str[0][((sign == 1) ? width : ++width)] = '0';
    }
    free(tmp);
    free(new);
}

void        fill_to_string(int size, char ch, char **string, int sign)
{
    char    *tmp;
    char    *zeros;

    if (!(zeros = (char *)malloc(sizeof(char) * (size + 1 + sign))))
        return ;
    zeros[size + sign] = '\0';
    tmp = *string;
    ft_memset(zeros, (int)ch, (size + sign));
    *string = ft_strjoin(zeros, (tmp + sign));
    if (sign > 0)
        string[0][((sign == 1) ? 0 : 1)] = ((sign == 1) ? tmp[0] : tmp[1]);
    free(zeros);
    free(tmp);
}

void         set_precision_numbers(t_data *convert, char **string)
{
    int   size;
    int   sign;

    size = ft_strlen(*string);
    if (spec_is_numbers(convert->specifier) && convert->specifier != 'x' &&
        convert->specifier != 'X')
        sign = (**string == '+' || **string == '-' || **string == ' ') ? 1 : 0;
    else
        sign = (string[0][1] == 'x' || string[0][1] == 'X') ? 2 : 0;
    if ((size - sign) < convert->precision && spec_is_numbers(convert->specifier))
    {
        fill_to_string((convert->precision - (size - sign)), '0', string, sign);
    }
    if (convert->width > ft_strlen(*string))
        check_width_numbers(convert, string, (convert->width - ft_strlen(*string)), sign);
}
