/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 10:49:40 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:25:12 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Norm - OK, leaks - ?
*/

char			*ft_str_reverse(char *str)
{
	size_t		i;
	char		*new;
	size_t		size;

	i = 0;
	if (!str)
		return (0);
	size = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	new[size] = '\0';
	while (size > 0)
	{
		new[i++] = str[size - 1];
		size--;
	}
	return (new);
}
