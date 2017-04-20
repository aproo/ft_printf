/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 23:34:37 by vmakahon          #+#    #+#             */
/*   Updated: 2016/12/26 23:34:37 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	new = NULL;
	if (!(s))
		return (NULL);
	end = ft_strlen(s) - 1;
	while (*(s + start) == ' ' || *(s + start) == '\n' || *(s + start) == '\t')
		start++;
	while ((*(s + end) == ' ' || *(s + end) == '\n'
		|| *(s + end) == '\t') && end > 0)
		end--;
	if (start > end)
		return (ft_strdup("\0"));
	new = ft_strsub(s, start, (end + 1 - start));
	return (new);
}
