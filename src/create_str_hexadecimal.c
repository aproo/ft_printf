/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:28:49 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:21:01 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Norm - OK, leaks - No?
*/

static uintmax_t	set_leght_hexadecimal(int len, va_list *args)
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

char				*create_str_hexadecimal(t_data *convert, va_list *args)
{
	char			*tmp;
	uintmax_t		value;
	char			*result;

	result = NULL;
	value = set_leght_hexadecimal(convert->lenght, args);
	if (convert->set_precision && convert->specifier != '%' && !value)
		result = ft_strdup("");
	else if (convert->specifier == 'x')
		result = ft_itoa_uint_max(value, 16);
	else if (convert->specifier == 'X')
		result = ft_itoa_uint_max_upper(value, 16);
	if (convert->flags.hashtag && result[0] != '0' && ft_strcmp(result, ""))
	{
		tmp = result;
		if (convert->specifier == 'x')
			result = ft_strjoin("0x", tmp);
		else
			result = ft_strjoin("0X", tmp);
		free(tmp);
	}
	convert->free = 1;
	set_precision_numbers(convert, &result);
	return (result);
}
