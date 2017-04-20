/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:34:58 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 17:34:59 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	psrc = NULL;
	pdst = NULL;
	while (i < n)
	{
		psrc = ((unsigned char *)src + i);
		pdst = ((unsigned char *)dst + i);
		*pdst = *psrc;
		if (*psrc == ch)
			return (pdst + 1);
		i++;
	}
	return (NULL);
}
