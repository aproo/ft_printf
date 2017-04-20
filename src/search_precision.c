/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:24:45 by vlad              #+#    #+#             */
/*   Updated: 2017/03/20 21:45:03 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		it_is_flags(char flag)
{
	return ((flag == '+' || flag == '-' || flag == ' ') ? 1 : 0);
}

int				search_precision(va_list *args, t_string *rsrc, t_data *convert)
{
	char		ch;
	size_t		i;

	ch = *current_str(*rsrc, 0);
	if (ch == '.')
	{
		rsrc->current_index++;
		if ((ch = *current_str(*rsrc, 0)) == '*')
		{
			convert->precision = va_arg(*args, unsigned int);
			rsrc->current_index++;
//			printf("Search_precision done!	[%c] = [%i]\n", ch, convert->precision);
		}
		else if (ft_isdigit(*current_str(*rsrc, 0)) || it_is_flags(ch))
		{
			if (it_is_flags(ch))
				search_flags(rsrc, &convert->flags);
			convert->precision = ft_atoi(rsrc->str + rsrc->current_index);
			i = convert->precision;
			if (!i)
            {
                convert->set_precision = 1;
                rsrc->current_index++;
            }
			while (i)
			{
				i /= 10;
				rsrc->current_index++;
			}
		}
        else
            convert->set_precision = 1;
		return (OK);
//		printf("Search_precision done!	[%i]\n", convert->precision);
	}
	else
//		printf("Search_precision done!	[No precision]\n");
	return (OK);
}