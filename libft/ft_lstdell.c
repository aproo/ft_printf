/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:51:06 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/02 21:51:06 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdell(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!(alst) || !(del))
		return ;
	tmp = *alst;
	*alst = tmp->next;
	del(tmp->content, tmp->content_size);
	free(tmp);
}
