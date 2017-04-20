/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:06 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 16:24:06 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = (char *)s;
	while (i < n)
	{
		if (*(pointer + i) == 0)
			i++;
		else
		{
			*(pointer + i) = 0;
			i++;
		}
	}
}
