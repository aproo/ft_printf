/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:42:40 by vlad              #+#    #+#             */
/*   Updated: 2017/04/07 12:18:13 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//no leaks

void	search_specificars(va_list *args, t_string *rsrc)
{
	char	ch;

	while ((ch = *(current_str(*rsrc, 0))))
	{
		if (ch == '%')
			analyze_specificar(args, rsrc);
		else
		{
			ft_putchar(ch);
			rsrc->current_index++;
			rsrc->count_print++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_string	rsrc;
	va_list		args;

	ft_szero(&rsrc, NULL, NULL);
	rsrc.str = format;
	va_start(args, format);
	search_specificars(&args, &rsrc);
	va_end(args);
	return (rsrc.count_print);
}
