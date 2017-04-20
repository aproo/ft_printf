/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 22:56:36 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/26 22:56:37 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!(substr = ft_memalloc(len + 1)) || !(s))
		return (NULL);
	while (i < len)
	{
		*(substr + i) = *(s + start);
		start++;
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
