/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_specificar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:57:02 by vlad              #+#    #+#             */
/*   Updated: 2017/05/02 09:16:39 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - Ok, leaks - OK.
*/

int		ft_it_is_spec(char ch)
{
	if (ch == 's' || ch == 'S' || ch == 'p' || ch == 'd' || ch == 'D' || \
		ch == 'i' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' || \
		ch == 'x' || ch == 'X' || ch == 'c' || ch == 'C' || ch == '%' || \
		ch == '\0' || ch == 'n')
	{
		return (1);
	}
	else if (ch == 'h' || ch == 'l' || ch == 'z' || ch == 'j' || ch == '.' || \
			ch == '+' || ch == ' ' || ch == '0' || ch == '#' || ch == '-' ||
			ch == '*' || ft_isdigit(ch))
		return (0);
	else if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && ch)
	{
		return (1);
	}
	return (0);
}

void	analyze_specificar(va_list *args, t_string *rsrc)
{
	char	ch;
	t_data	convert;

	rsrc->current_index++;
	ft_szero(NULL, &convert, &convert.flags);
	if (!(ch = *current_str(*rsrc, 0)))
		return ;
	if (ch == '%')
	{
		ft_putchar('%');
		rsrc->current_index++;
		rsrc->count_print++;
		return ;
	}
	if (((check_all(args, rsrc, &convert)) == OK) &&
			(error(rsrc, &convert) == OK))
		print_result(args, rsrc, &convert);
	else
		rsrc->error = ERROR;
}

int		check_all(va_list *args, t_string *rsrc, t_data *convert)
{
	int		spec;
	int		nodata;

	spec = OK;
	nodata = ERROR;
	while (spec == OK && nodata != OK)
	{
		nodata = OK;
		if (search_flags(rsrc, &convert->flags) == OK)
			nodata++;
		if (search_width(args, rsrc, convert) == OK)
			nodata++;
		if (search_precision(args, rsrc, convert) == OK)
			nodata++;
		if (search_length(rsrc, convert, *current_str(*rsrc, 0)) == OK)
			nodata++;
		spec = ft_it_is_spec(*current_str(*rsrc, 0));
	}
	if (identify_specifiers(rsrc, convert) == ERROR)
		return (ERROR);
	add_fix_main(rsrc, convert);
	return (OK);
}
