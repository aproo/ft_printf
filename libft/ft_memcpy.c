/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:20:34 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 17:20:34 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	i = 0;
	psrc = NULL;
	pdst = NULL;
	while (i < n)
	{
		psrc = ((unsigned char *)src + i);
		pdst = ((unsigned char *)dst + i);
		*pdst = *psrc;
		i++;
	}
	return (dst);
}
