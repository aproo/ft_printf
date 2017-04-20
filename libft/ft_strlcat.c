/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:48:30 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/03 13:48:31 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cdst;
	size_t	csrc;
	size_t	csum;
	size_t	t;

	csrc = ft_strlen(src);
	cdst = ft_strlen(dst);
	csum = csrc + cdst;
	t = cdst + 1;
	if (size < cdst)
		csum = csrc + size;
	if (size > csum)
		while (*src)
			dst[cdst++] = *src++;
	else
		while (size-- > t)
			dst[cdst++] = *src++;
	dst[cdst] = '\0';
	return (csum);
}
