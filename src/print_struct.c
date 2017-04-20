/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:19:31 by vmakahon          #+#    #+#             */
/*   Updated: 2017/03/25 20:01:07 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_struct(t_string *rsrc, t_data *convert, t_flags *flags)
{
	if (rsrc)
		printf("struct -	[rsrc]\nstr -		[%s]\ncurrent_index -	[%zu]\ncount_print -	[%zu]\n", rsrc->str, rsrc->current_index, rsrc->count_print);
	if (convert)
		printf("struct -	[convert]\nwidth -		[%zu]\nprecision -	[%d]\nlenght -	[%d]\n", convert->width, convert->precision, convert->lenght);
	if (flags)
		printf("struct -	[flags]\nleft_justify -	[%d]\nsign -		[%d]\nspace -		[%d]\nfill_zeros -	[%d]\nhashtag -	[%d]\n",
			flags->left_justify, flags->sign, flags->space, flags->fill_zeros, flags->hashtag);
}
