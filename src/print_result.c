/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:02:11 by vlad              #+#    #+#             */
/*   Updated: 2017/06/08 05:11:46 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	sSpdDioOuUxXcC
**	norm - OK; leaks - No;
**
**	else if ((sp == 'c' && convert->lenght == L) || (sp == 'C'))
**		return (create_str_char_wide(rsrc, convert,
**					(wchar_t)va_arg(*args, wint_t)));
*/

static char	*create_str_percent(t_data *convert)
{
	char	*result;

	result = ft_strdup("%");
	convert->free = 1;
	set_precision_numbers(convert, &result);
	return (result);
}

char		*choose_specifiers(va_list *args, t_string *rsrc,
		t_data *convert, char sp)
{
	if ((sp == 's' && convert->lenght == L) || (sp == 'S'))
		return (create_str_string_wide(rsrc, convert,
					va_arg(*args, wchar_t *)));
	else if (sp == 's' && convert->lenght == 0)
		return (create_str_string(convert, va_arg(*args, char *)));
	else if (sp == 'o' || sp == 'O')
		return (create_str_octal(convert, args));
	else if (sp == 'x' || sp == 'X')
		return (create_str_hexadecimal(convert, args));
	else if (sp == 'd' || sp == 'D' || sp == 'i' || sp == 'u' || sp == 'U')
		return (create_str_decimal(convert, args));
	else if (sp == 'p')
		return (create_str_pointer(convert, va_arg(*args, void *)));
	else if (sp == '%')
		return (create_str_percent(convert));
	else if (sp == '&')
		create_char(rsrc, convert, (unsigned char)*current_str(*rsrc, -1));
	convert->free = 1;
	return (ft_strdup(""));
}

void		print_result(va_list *args, t_string *rsrc, t_data *convert)
{
	char	*result;

	if ((convert->specifier == 'c' && convert->lenght == 0) ||
			(convert->specifier == 'c' && convert->lenght == L) ||
			(convert->specifier == 'C'))
		create_char(rsrc, convert, (unsigned char)va_arg(*args, int));
	else
	{
		result = choose_specifiers(args, rsrc, convert, convert->specifier);
		rsrc->count_print += ft_strlen(result);
		ft_putstr(result);
		if (convert->free == 1)
			free(result);
	}
}
