/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:26:31 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/04 17:26:32 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	if (!(ft_strlen(little)))
		return ((char *)big);
	i = 0;
	while (big[i] && i != len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while ((big[k] == little[j]) && little[j] && k != len)
			{
				j++;
				k++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
