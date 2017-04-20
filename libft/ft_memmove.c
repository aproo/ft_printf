/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 17:36:07 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 17:36:08 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*psrc;
	unsigned char		*pdst;

	i = 0;
	psrc = ((const unsigned char *)src);
	pdst = ((unsigned char *)dst);
	if (src > dst)
	{
		while (i < len && len != 0)
		{
			*(pdst + i) = *(psrc + i);
			i++;
		}
	}
	else if (src < dst && len != 0)
	{
		while (len > 0)
		{
			*(pdst + len - 1) = *(psrc + len - 1);
			len--;
		}
	}
	return (pdst);
}
