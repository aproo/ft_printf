/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:31:35 by vmakahon          #+#    #+#             */
/*   Updated: 2016/11/29 18:57:55 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*array;

	i = 0;
	while (s1[i])
		i++;
	if (!(s1) || !(array = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
