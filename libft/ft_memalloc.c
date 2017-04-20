/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:14:10 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/18 17:14:11 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*array;

	array = NULL;
	if (!(array = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(array, size);
	return (array);
}
