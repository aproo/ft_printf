/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:37:51 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 17:37:52 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	ch;

	i = 0;
	ps = NULL;
	ch = (unsigned char)c;
	while (i < n)
	{
		ps = (unsigned char *)(s + i);
		if (*ps == ch)
			return (ps);
		i++;
	}
	return (NULL);
}
