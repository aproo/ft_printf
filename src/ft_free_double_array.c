/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 11:43:17 by vmakahon          #+#    #+#             */
/*   Updated: 2017/06/08 11:43:19 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_free_double_array(char ***str)
{
	int 	i;
	char 	**ptr;

	i = 0;
	ptr = *str;
	while (ptr[i] != NULL && str)
	{
		ft_strdel(&ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}
