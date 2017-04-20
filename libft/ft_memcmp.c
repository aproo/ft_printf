/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:38:04 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 17:38:05 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = NULL;
	ps2 = NULL;
	while (i < n)
	{
		ps1 = ((unsigned char *)s1 + i);
		ps2 = ((unsigned char *)s2 + i);
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		i++;
	}
	return (0);
}
