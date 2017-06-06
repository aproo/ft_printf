/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_str_wide.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 06:28:04 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:10:52 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	norm - OK; leaks - ?;
*/

static int	amount_enters(char *str)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			n++;
	}
	return (n);
}

void		convert_without_enter(char **str)
{
	int		i;
	int		n;
	char	*new;
	char	*tmp;

	i = -1;
	n = amount_enters(*str);
	new = (char *)malloc(sizeof(char) * (ft_strlen(*str) - n + 1));
	new[(ft_strlen(*str) - n)] = '\0';
	n = 0;
	tmp = *str;
	while (str[0][++i])
	{
		if (str[0][i] != '\n')
			new[n++] = str[0][i];
	}
	*str = new;
	free(tmp);
}

void		convert_with_enter(char **result, wchar_t *str)
{
	size_t	i;
	char	*tmp;
	char	*fre;

	i = 0;
	*result = ft_strdup("");
	while (str[i])
	{
		if (str[i] > 127)
			tmp = convert_char(str[i], 0, 0, 2);
		else
		{
			tmp = ft_strnew(1);
			tmp[0] = str[i];
		}
		fre = *result;
		*result = ft_strjoin(*result, tmp);
		free(fre);
		free(tmp);
		fre = *result;
		*result = ft_strjoin(*result, "\n");
		free(fre);
		i++;
	}
}

char		*set_precision_str_wide(t_data *convert, char *str)
{
	int		i;
	int		j;
	int		x;
	char	*result;

	j = 0;
	x = 0;
	i = convert->precision;
	result = (char *)malloc(sizeof(char) * ((convert->precision * 2) + 1));
	result[(convert->precision * 2)] = '\0';
	while (i >= 0 && str[x])
	{
		while (str[(j + x)] != '\n')
			j++;
		while (j-- <= i-- && j >= 0 && i >= 0)
		{
			result[x] = str[x];
			x++;
		}
		if (str[x] == '\n')
			result[x++] = '\n';
		j = 0;
	}
	result[x] = '\0';
	return (result);
}

char		*set_width_str_wide(t_data *convert, char *str)
{
	int		n;
	int		len;
	char	*tmp;
	char	*result;

	len = ft_strlen(str);
	n = amount_enters(str);
	tmp = (char *)malloc(sizeof(char) * convert->width - len + n + 1);
	tmp[(convert->width - len)] = '\0';
	if (convert->flags.fill_zeros)
		ft_memset(tmp, '0', ((convert->width - len + n)));
	else
		ft_memset(tmp, ' ', ((convert->width - len + n)));
	if (convert->flags.left_justify)
		result = ft_strjoin(str, tmp);
	else
		result = ft_strjoin(tmp, str);
	free(tmp);
	return (result);
}
