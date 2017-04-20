/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_all_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:26:36 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/03 08:22:46 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char        *set_precision_str(t_data *convert, char *str)
{
    int     i;
    char    *result;

    i = 0;
    result = (char *)malloc(sizeof(char) * convert->precision + 1);
    result[convert->precision] = '\0';
    while (convert->precision > i)
    {
        result[i] = str[i];
        i++;
    }
    return (result);
}

char        *set_width_str(t_data *convert, char *str)
{
    char 	*tmp;
    char    *result;

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
    if (convert->specifier == 'p' && !convert->flags.left_justify && convert->flags.fill_zeros)
    {
        result[1] = 'x';
        result[convert->width - ft_strlen(str) + 1] = '0';
    }
    return (result);
}

char		*create_chars_wide(t_string *rsrc, wchar_t* str)
{
	(void)rsrc;
	size_t	i;
	char	*result;
	char 	*tmp;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		tmp = convert_char(str[i], 0, 0, 2);
		result = ft_strjoin(result, tmp);
		i++;
	}
	return (result);
}

char		*create_str_string(t_data *convert, char* str)
{
    char    *result;

    if (!str)
        result = ft_strdup("(null)");
    else
        result = str;
    if (convert->precision || convert->set_precision)
        result = set_precision_str(convert, str);
	if (result && convert->width)
		result = set_width_str(convert, result);
	return (result);

}

char		*create_str_string_wide(t_string *rsrc, wchar_t* str)
{
	if (str)
		return (create_chars_wide(rsrc, str));
	else
	{
		ft_putstr("(NULL)");
		rsrc->count_print += 6;
	}
	return ("");
}