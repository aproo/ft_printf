/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_all_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:29:17 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 08:04:19 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*convert_char(wchar_t ch, size_t len, int i, int div)
{
	int			y;
	char		*sch;

	if (!(sch = (char *)malloc(sizeof(char) * 33)))
        return (NULL);
	if (ch <= 0x7F)
		len = 1;
	else if (ch <= 0x7FF)
		len = 2;
	else if (ch <= 0xFFFF)
		len = 3;
	else if (ch <= 0x10FFFF)
		len = 4;
	y = (int)ch;
	while (y && (div = y % 2) >= 0)
	{
		sch[i++] = div + '0';
		y /= 2;
	}
	sch[i] = '\0';
	sch = ft_str_reverse(sch);
    return (convert_utf8(sch, len));
}

void		create_char(t_string *rsrc, t_data *convert, unsigned char ch)
{
    int     i;

    i = convert->width;
        if (convert->flags.left_justify)
            ft_putchar(ch);
        while (--i > 0)
        {
            ft_putchar(((convert->flags.fill_zeros) ? '0' : ' '));
            rsrc->count_print++;
        }
        if (!convert->flags.left_justify)
            ft_putchar(ch);
		rsrc->count_print++;
}

char		*create_str_char_wide(t_string *rsrc, t_data *convert, wchar_t ch)
{
	if (ch)
    {
        if ((int)ch > 127)
            return (convert_char(ch, 0, 0, 2));
        else
            create_char(rsrc, convert, (unsigned char)ch);
    }
	else
	{
		ft_putchar(ch);
		rsrc->count_print++;
	}
	return ("");
}