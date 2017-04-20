/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:23:27 by vlad              #+#    #+#             */
/*   Updated: 2017/03/20 21:44:38 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		search_flags(t_string *rsrc, t_flags *flags)
{
	char	ch;

	ch = *current_str(*rsrc, 0);
	if (ch == '-' || ch == '+' || ch == ' ' || ch == '#' || ch == '0')
	{
		while (ch)
		{
			if (ch == '-')
				flags->left_justify = 1;
			else if (ch == '+')
				flags->sign = 1;
			else if (ch == ' ')
				flags->space = 1;
			else if (ch == '0')
				flags->fill_zeros = 1;
			else if (ch == '#')
				flags->hashtag = 1;
			else
				return (OK);
//			printf("\nSearch_flags done!	[%c]\n", ch);
			rsrc->current_index++;
			ch = *current_str(*rsrc, 0);
		}
		return (OK);
	}
//	else
//		printf("\nSearch_flags done!	[No flag]\n");
	return (OK);
}