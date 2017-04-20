/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 23:02:11 by vlad              #+#    #+#             */
/*   Updated: 2017/04/03 09:27:27 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	sSpdDioOuUxXcC
*/

static char *create_str_percent(t_data *convert)
{
	char 	*result;

	result = ft_strdup("%");
	set_precision_numbers(convert, &result);
	return (result);
}

char		*choose_specifiers(va_list *args, t_string *rsrc, t_data *convert, char sp)
{
	if ((sp == 's' && convert->lenght == L) || (sp == 'S'))//good
		return (create_str_string_wide(rsrc, va_arg(*args, wchar_t *)));
	else if (sp == 's' && convert->lenght == 0)
		return (create_str_string(convert, va_arg(*args, char *)));
	else if ((sp == 'c' && convert->lenght == L) || (sp == 'C'))//good
		return (create_str_char_wide(rsrc, convert, (wchar_t)va_arg(*args, wint_t)));
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
	return ("ERROR_SPECIFIERS");
}

void	print_result(va_list *args, t_string *rsrc, t_data *convert)
{
	char	*result;

    if (convert->specifier == 'c' && convert->lenght == 0)
        create_char(rsrc, convert, (unsigned char)va_arg(*args, int));
	else
    {
        result = choose_specifiers(args, rsrc, convert, convert->specifier);
        rsrc->count_print += ft_strlen(result);
        ft_putstr(result);
//        free(result);
    }
}
