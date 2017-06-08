/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 21:01:15 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 09:14:27 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** define [H	1]	 [HH	2]	[L	3]	[LL		4]	[J	5]	 [Z	6]
** norm - OK; leaks - No;
*/

void				set_flags_decimal(char sp, t_flags flags, char **string)
{
	char			*flag;
	char			*result;
	char			*tmp;

	if (**string >= '0' && **string <= '9')
	{
		flag = NULL;
		if (flags.sign && sp != 'U' && sp != 'u')
			flag = "+";
		else if (flags.space)
			flag = " ";
		if (flag)
		{
			tmp = *string;
			result = ft_strjoin(flag, *string);
			*string = result;
			free(tmp);
		}
	}
}

static intmax_t		set_leght_sign_decimal(int len, va_list *args)
{
	intmax_t		value;

	value = 0;
	if (len == L)
		value = va_arg(*args, long int);
	else if (len == LL)
		value = va_arg(*args, long long int);
	else if (len == J)
		value = va_arg(*args, intmax_t);
	else if (len == Z)
		value = va_arg(*args, size_t);
	else if (len == H)
		value = (short int)va_arg(*args, int);
	else if (len == HH)
		value = (char)va_arg(*args, int);
	else if (len == 0)
		value = va_arg(*args, int);
	return (value);
}

static uintmax_t	set_leght_usign_decimal(int len, va_list *args)
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

char				*create_str_decimal(t_data *convert, va_list *args)
{
	intmax_t		value;
	uintmax_t		uvalue;
	char			*result;

	if (convert->specifier == 'U' || convert->specifier == 'u')
	{
		uvalue = set_leght_usign_decimal(convert->lenght, args);
		if (convert->set_precision && convert->specifier != '%' && !uvalue)
			result = ft_strdup("");
		else
			result = ft_itoa_uint_max(uvalue, 10);
	}
	else
	{
		value = set_leght_sign_decimal(convert->lenght, args);
		if (convert->set_precision && convert->specifier != '%' && !value)
			result = ft_strdup("");
		else
			result = ft_itoa_int_max(value, 10);
	}
	convert->free = 1;
	set_flags_decimal(convert->specifier, convert->flags, &result);
	set_precision_numbers(convert, &result);
	return (result);
}
