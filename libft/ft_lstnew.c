/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:46:02 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/02 20:46:03 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t cont_size)
{
	t_list	*new;
	void	*p;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		if (!(p = ft_memdup(content, cont_size)))
		{
			free(new);
			return (0);
		}
		new->content = p;
		new->content_size = cont_size;
	}
	else
	{
		new->content = 0;
		new->content_size = 0;
	}
	new->next = 0;
	return (new);
}
