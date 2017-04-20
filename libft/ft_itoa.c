/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 19:21:09 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/01 19:21:10 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countchars(int nbr)
{
	size_t	i;

	i = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int		ft_nbr_is_negative(int nbr, char *array, size_t i)
{
	*(array + i++) = '-';
	if (nbr == -2147483648)
	{
		*(array + i++) = '2';
		nbr %= 1000000000;
	}
	return (-nbr);
}

char			*ft_itoa(int nbr)
{
	char	*array;
	int		div;
	size_t	i;

	i = 0;
	div = 1000000000;
	if (!(array = ft_strnew(ft_countchars(nbr))))
		return (NULL);
	if (nbr < 0)
		nbr = ft_nbr_is_negative(nbr, array, i);
	while (div > nbr && div >= 10)
		div /= 10;
	i = ft_strlen(array);
	while (div >= 10)
	{
		*(array + i++) = ('0' + (char)(nbr / div));
		nbr %= div;
		div /= 10;
	}
	*(array + i) = '0' + nbr;
	return (array);
}
