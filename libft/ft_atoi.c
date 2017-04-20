/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:40:26 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/26 19:12:02 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + ((int)*str++ - '0');
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(res * sign));
}
