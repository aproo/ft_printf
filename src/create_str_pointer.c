/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 09:25:06 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:11:39 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - No
*/

void			set_precision_pointer(t_data *convert, char **result)
{
	size_t		len;
	char		*new;

	len = ft_strlen(*result);
	new = (char *)malloc(sizeof(char) * (convert->precision - (len - 2)));
	new[(convert->precision - (len - 2))] = '\0';
	ft_memset(new, '0', (convert->precision - (len - 2)));
	*result = ft_strjoin(new, *result);
	result[0][1] = 'x';
	result[0][(ft_strlen(new) + 1)] = '0';
	free(new);
}

char			*create_str_pointer(t_data *convert, void *pointer)
{
	uintmax_t	nb;
	char		*result;
	char		*tmp;

	nb = (uintmax_t)pointer;
	if ((convert->set_precision) && !nb)
		result = ft_strdup("");
	else
		result = ft_itoa_uint_max(nb, 16);
	tmp = result;
	result = ft_strjoin("0x", tmp);
	free(tmp);
	if (convert->precision > ((int)ft_strlen(result) - 2))
		set_precision_pointer(convert, &result);
	if ((result && (convert->width > ft_strlen(result))))
	{
		tmp = result;
		result = set_width_str(convert, result);
		free(tmp);
	}
	convert->free = 1;
	return (result);
}
