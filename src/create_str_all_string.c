/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_all_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:26:36 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:07:35 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	norm - OK; leaks - NO;
*/

char		*set_precision_str(t_data *convert, char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(sizeof(char) * convert->precision + 1);
	result[convert->precision] = '\0';
	while (convert->precision > i)
	{
		result[i] = str[i];
		i++;
	}
	convert->free = 1;
	return (result);
}

char		*set_width_str(t_data *convert, char *str)
{
	char	*tmp;
	char	*result;

	tmp = (char *)malloc(sizeof(char) * convert->width - ft_strlen(str) + 1);
	tmp[(convert->width - ft_strlen(str))] = '\0';
	if (convert->flags.fill_zeros)
		ft_memset(tmp, '0', ((convert->width - ft_strlen(str))));
	else
		ft_memset(tmp, ' ', ((convert->width - ft_strlen(str))));
	if (convert->flags.left_justify)
		result = ft_strjoin(str, tmp);
	else
		result = ft_strjoin(tmp, str);
	free(tmp);
	if (convert->specifier == 'p' && !convert->flags.left_justify
		&& convert->flags.fill_zeros)
	{
		result[1] = 'x';
		result[convert->width - ft_strlen(str) + 1] = '0';
	}
	convert->free = 1;
	return (result);
}

char		*create_chars_wide(t_data *convert, wchar_t *str)
{
	char	*result;
	char	*tmp;
	size_t	len_n;

	convert_with_enter(&result, str);
	if (convert->precision || convert->set_precision)
	{
		tmp = result;
		result = set_precision_str_wide(convert, result, 0, 0);
		free(tmp);
	}
	len_n = amount_enters(result);
	if (result && ((size_t)convert->width > (ft_strlen(result) - len_n)))
	{
		tmp = result;
		result = set_width_str_wide(convert, result);
		free(tmp);
	}
	convert_without_enter(&result);
	convert->free = 1;
	return (result);
}

char		*create_str_string(t_data *convert, char *str)
{
	char	*result;
	char	*tmp;

	tmp = NULL;
	if (!str && (convert->free = 1 > 0))
	{
		result = ft_strdup("(null)");
		tmp = result;
	}
	else
		result = str;
	if (convert->precision || convert->set_precision)
	{
		result = set_precision_str(convert, result);
		if (tmp)
			free(tmp);
		tmp = result;
	}
	if (result && (((size_t)convert->width > ft_strlen(result))))
	{
		result = set_width_str(convert, result);
		if (tmp)
			free(tmp);
	}
	return (result);
}

char		*create_str_string_wide(t_string *rsrc, t_data *cnv, wchar_t *str)
{
	if (str)
		return (create_chars_wide(cnv, str));
	else
	{
		ft_putstr("(null)");
		rsrc->count_print += 6;
	}
	cnv->free = 1;
	return (ft_strdup(""));
}
