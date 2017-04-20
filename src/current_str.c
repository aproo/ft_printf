/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:51:50 by vlad              #+#    #+#             */
/*   Updated: 2017/03/25 19:37:17 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*current_str(t_string rsrc, int index)
{
	const char	*str;
	int			current;

	current = rsrc.current_index + index;
	str = rsrc.str;
	return (str + current);
}
