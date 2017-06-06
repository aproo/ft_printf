/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:23:03 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:07:29 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - ?
*/

char			*convert_to_integer(char **str, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return ("NULL");
	while (i < len)
	{
		result[i] = ft_binary_to_decimal(str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

char			*edit_bytes(char *sch, char **str, size_t len)
{
	size_t		j;
	size_t		size;
	char		*result;
	size_t		lenght;

	lenght = len;
	size = ft_strlen(sch);
	while (len > 0)
	{
		j = 7;
		while (j > 1 && size > 0)
		{
			str[len - 1][j--] = sch[size - 1];
			size--;
		}
		len--;
	}
	result = convert_to_integer(str, lenght);
	return (result);
}

char			*first_byte(size_t len, char *first_byte)
{
	size_t		i;

	i = 0;
	while (i < 8)
	{
		first_byte[i] = ((len > i) && (len > 1)) ? '1' : '0';
		i++;
	}
	first_byte[i] = '\0';
	return (first_byte);
}

char			*other_byte(char *other_byte)
{
	size_t		i;

	i = 0;
	while (i < 8)
	{
		other_byte[i] = (i == 0) ? '1' : '0';
		i++;
	}
	other_byte[i] = '\0';
	return (other_byte);
}

char			*convert_utf8(char *sch, size_t len)
{
	char		**str;
	size_t		byte;
	char		*result;

	byte = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (byte <= len)
		if (!(str[byte++] = (char *)malloc(sizeof(char) * 9)))
			return (NULL);
	byte = 1;
	while (byte <= len)
	{
		if (byte == 1)
			str[byte - 1] = first_byte(len, str[byte - 1]);
		else if ((byte > 1) && (byte < 5))
			str[byte - 1] = other_byte(str[byte - 1]);
		byte++;
	}
	str[byte - 1] = NULL;
	result = edit_bytes(sch, str, len);
	return (result);
}
