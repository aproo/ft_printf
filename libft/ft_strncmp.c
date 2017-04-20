/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:50:38 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/04 20:50:39 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ch1;
	unsigned char	*ch2;

	ch1 = (unsigned char *)s1;
	ch2 = (unsigned char *)s2;
	while (*ch1 == *ch2 && n--)
	{
		if (*ch1 == '\0')
			return (0);
		ch1++;
		ch2++;
	}
	if (!n)
		return (0);
	return (*ch1 - *ch2);
}
