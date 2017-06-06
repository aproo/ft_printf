/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:52:19 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:34:26 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		error_sign_decimal(intmax_t value, int len)
{

	if (len == HH && (value < INT8_MIN || value > INT8_MAX))
	{
		ft_putstr("ERROR :format signed char\n");
		return (ERROR);
	}
	else if (len == H && (value < INT16_MIN || value > INT16_MAX))
	{
		ft_putstr("ERROR :format signed short int\n");
		return (ERROR);
	}
	else if ((len == L) && (value < INT32_MIN))
	{
		ft_putstr("ERROR :format long int\n");
		return (ERROR);
	}
	else if ((len >= LL) && (value < INT64_MIN || value > INT64_MAX))
	{
		ft_putstr("ERROR :format long long int\n");
		return (ERROR);
	}
	else if ((len == 0 && (value > INT32_MAX)))
	{
		ft_putstr("ERROR :format int\n");
		return (ERROR);
	}
	return (OK);
}

int			error_usign_decimal(intmax_t value, int len)
{
	(void)value;
	(void)len;
	return (OK);
}

int			error(t_string *rsrc, t_data *convert)
{
	int		lenght;
	char	spec;
	(void)rsrc;

	spec = convert->specifier;
	lenght = convert->lenght;
	return (OK);
}
