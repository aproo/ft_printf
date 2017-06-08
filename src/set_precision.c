/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:05:24 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:11:57 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	norm - OK; leaks - No;
*/

static int	spec_is_numbers(char ch)
{
	return ((ch == 'd' || ch == 'D' || ch == 'i' || ch == 'o' ||
			ch == 'O' || ch == 'u' || ch == 'U' || ch == 'x' ||
			ch == 'X') ? 1 : 0);
}

void		check_width_numbers(t_data *cnv, char **str,
								size_t width, size_t sign)
{
	char	*tmp;
	char	*new;

	tmp = *str;
	new = ft_strnew(width);
	if ((cnv->flags.fill_zeros && !cnv->precision &&
			!cnv->set_precision) || (cnv->specifier == '%' &&
			!cnv->flags.left_justify && cnv->flags.fill_zeros))
		ft_memset(new, '0', width);
	else
		ft_memset(new, ' ', width);
	if (cnv->flags.left_justify)
		*str = ft_strjoin(tmp, new);
	else
		*str = ft_strjoin(new, tmp);
	if (sign > 0 && cnv->flags.fill_zeros)
	{
		str[0][((sign == 1) ? 0 : 1)] = ((sign == 1) ? tmp[0] : tmp[1]);
		str[0][((sign == 1) ? width : ++width)] = '0';
	}
	free(tmp);
	free(new);
}

void		fill_to_string(size_t size, char ch, char **string, size_t sign)
{
	char	*tmp;
	char	*zeros;

	if (!(zeros = (char *)malloc(sizeof(char) * (size + 1 + sign))))
		return ;
	zeros[size + sign] = '\0';
	tmp = *string;
	ft_memset(zeros, (int)ch, (size + sign));
	*string = ft_strjoin(zeros, (tmp + sign));
	if (sign > 0)
		string[0][((sign == 1) ? 0 : 1)] = ((sign == 1) ? tmp[0] : tmp[1]);
	free(zeros);
	free(tmp);
}

void		set_precision_numbers(t_data *convert, char **str)
{
	size_t	size;
	size_t	sign;

	size = ft_strlen(*str);
	if (spec_is_numbers(convert->specifier) && convert->specifier != 'x' &&
			convert->specifier != 'X')
		sign = (**str == '+' || **str == '-' || **str == ' ') ? 1 : 0;
	else
		sign = (str[0][1] == 'x' || str[0][1] == 'X') ? 2 : 0;
	if ((int)(size - sign) < convert->precision &&
			spec_is_numbers(convert->specifier))
		fill_to_string((convert->precision - (size - sign)), '0', str, sign);
	if (convert->width > ft_strlen(*str))
		check_width_numbers(convert, str, (convert->width - ft_strlen(*str)),
							sign);
}
