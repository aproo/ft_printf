/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:27:17 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 09:18:28 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	norm - OK; leaks - may be;
*/

static uintmax_t	set_leght_octal(int len, va_list *args)
{
	uintmax_t		value;

	value = 0;
	if (len == L)
		value = va_arg(*args, unsigned long int);
	else if (len == LL)
		value = va_arg(*args, unsigned long long int);
	else if (len == J)
		value = va_arg(*args, uintmax_t);
	else if (len == Z)
		value = va_arg(*args, size_t);
	else if (len == H)
		value = (unsigned short int)va_arg(*args, unsigned int);
	else if (len == HH)
		value = (unsigned char)va_arg(*args, unsigned int);
	else if (len == 0)
		value = va_arg(*args, unsigned int);
	return (value);
}

char				*create_str_octal(t_data *convert, va_list *args)
{
	char			*tmp;
	uintmax_t		value;
	char			*result;

	value = set_leght_octal(convert->lenght, args);
	if (convert->set_precision && convert->specifier != '%' && !value)
		result = ft_strdup("");
	else
		result = ft_itoa_uint_max_upper(value, 8);
	convert->free = 1;
	if (convert->flags.hashtag && (convert->precision ||
			convert->set_precision || value))
	{
		tmp = result;
		result = ft_strjoin("0", tmp);
		free(tmp);
	}
	set_precision_numbers(convert, &result);
	return (result);
}
