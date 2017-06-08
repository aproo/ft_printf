/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:52:19 by vmakahon          #+#    #+#             */
/*   Updated: 2017/05/02 09:34:26 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			error(t_string *rsrc, t_data *convert)
{
	int		lenght;
	char	spec;

	(void)rsrc;
	spec = convert->specifier;
	lenght = convert->lenght;
	return (OK);
}
