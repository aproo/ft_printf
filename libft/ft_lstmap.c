/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:04:34 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/02 21:04:35 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_delleted(void *content, size_t content_size)
{
	free(content);
	UNUS(content_size);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*end;
	t_list	*tmp;

	if (!(lst) || !(f))
		return (NULL);
	end = 0;
	tmp = 0;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (!tmp)
			break ;
		tmp = f(tmp);
		if (end)
			end->next = tmp;
		else
			head = tmp;
		end = tmp;
		lst = lst->next;
	}
	if (!tmp)
		ft_lstdel(&head, ft_lstmap_delleted);
	return (head);
}
