/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:16:58 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/03 14:16:58 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *mem, size_t size)
{
	void	*dst;

	dst = (void *)malloc(size);
	if (!dst)
		return (0);
	ft_memcpy(dst, mem, size);
	return (dst);
}
