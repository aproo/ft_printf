/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 10:59:55 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/02 10:59:56 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!(alst) || !(del))
		return ;
	tmp = *alst;
	*alst = 0;
	del(tmp->content, tmp->content_size);
	free(tmp);
	tmp = 0;
}
