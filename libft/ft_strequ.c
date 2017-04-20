/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 22:13:37 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/26 22:13:37 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if (!(s1) && !(s2))
		return (1);
	if (s1 && s2)
	{
		while (*(s1 + i) == *(s2 + i))
		{
			if (*(s1 + i) == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}