/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:00:32 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/17 16:00:32 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = (char *)b;
	while (i < len)
		*(pointer + i++) = c;
	return (pointer);
}
