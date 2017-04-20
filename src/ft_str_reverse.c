/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 10:49:40 by vmakahon          #+#    #+#             */
/*   Updated: 2017/04/07 10:51:39 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char 		*ft_str_reverse(char *str)
{
    size_t 	i;
    char    *new;
    size_t 	size;

    i = 0;
    if (!str)
        return (0);
    size = ft_strlen(str);
    if (!(new = (char *)malloc(sizeof(char) * size)))
        return (0);
    new[size] = '\0';
    while (size > 0)
    {
        new[i++] = str[size - 1];
        size--;
    }
    //printf("str [%s] size [%zu]\nnew [%s] size [%zu]", str, ft_strlen(str), new, ft_strlen(new));
    return (new);
}
