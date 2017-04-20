/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_specificar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:57:02 by vlad              #+#    #+#             */
/*   Updated: 2017/04/03 09:27:30 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//no leaks

void	analyze_specificar(va_list *args, t_string *rsrc)
{
	t_data	convert;
	char	ch;

	rsrc->current_index++;
	ft_szero(NULL, &convert, &convert.flags);
	ch = *current_str(*rsrc, 0);
	
	if (ch == '%')
	{
		ft_putchar('%');
		rsrc->current_index++;
		rsrc->count_print++;
		return ;
	}
	if (((check_all(args, rsrc, &convert)) == OK) && (error(rsrc, &convert) == OK))
	{
		print_result(args, rsrc, &convert);
	}
	else
	{
        rsrc->error = ERROR;
//		printf("---------ERROR Check--------\n");
//		print_struct(rsrc, &convert, &convert.flags);
	}
}

int		check_all(va_list *args, t_string *rsrc, t_data *convert)
{
	if (search_flags(rsrc, &convert->flags) == ERROR)
		return (ERROR);
	if (search_width(args, rsrc, convert) == ERROR)
		return (ERROR);
	if (search_precision(args, rsrc, convert) == ERROR)
		return (ERROR);
	if (search_length(rsrc, convert) == ERROR)
		return (ERROR);
	if (identify_specifiers(rsrc, convert) == ERROR)
		return (ERROR);
    add_fix_main(rsrc, convert);
	// print_struct(rsrc, convert, &convert->flags);
//	printf("-----Check all Done!-----\n");
	return (OK);
}
