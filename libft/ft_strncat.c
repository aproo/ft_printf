/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:01:47 by vmakahon          #+#    #+#             */
/*   Updated: 2016/11/29 20:27:05 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (n-- && s2[j])
		s1[i++] = s2[j++];
	if (s1)
		s1[i] = '\0';
	return (s1);
}
