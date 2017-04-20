/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 20:56:21 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/26 20:56:22 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(s) || !(f) || !(new = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (*(s + i))
	{
		*(new + i) = f(*(s + i));
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
