/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:19:31 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/18 18:19:31 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(str, '\0', (size + 1));
	return (str);
}
