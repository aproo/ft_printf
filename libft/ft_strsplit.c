/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 19:32:46 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/01 19:32:47 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_wordcount(const char *str, char delim)
{
	size_t	word;
	int		last_status;

	last_status = 1;
	word = 0;
	while (*str)
	{
		if (last_status != (*str == delim))
			if (last_status)
				word++;
		last_status = (*str == delim);
		str++;
	}
	return (word);
}

static char		*ft_strdup_space(const char *str, char delim)
{
	size_t	len;
	size_t	count;
	char	*dest;

	len = 0;
	while (str[len] && !(str[len] == delim))
		len++;
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	len = 0;
	count = 0;
	while (str[len] && !(str[len] == delim))
	{
		dest[count++] = str[len++];
	}
	dest[count] = '\0';
	return (dest);
}

static int		ft_addtotab(char **tab, size_t word,
							const char *strptr, char delim)
{
	char	*n;

	if (!(n = ft_strdup_space(strptr, delim)))
	{
		tab[word] = 0;
		ft_strdel(tab);
		return (0);
	}
	tab[word] = n;
	return (1);
}

char			**ft_strsplit(const char *str, char delim)
{
	size_t		word;
	int			last_status;
	char		**tab;

	if (!str)
		return (NULL);
	word = ft_split_wordcount(str, delim);
	if (!(tab = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	last_status = 1;
	word = 0;
	while (*str)
	{
		if (last_status != (*str == delim))
			if (last_status && !ft_addtotab(tab, word++, str, delim))
				return (NULL);
		last_status = (*str == delim);
		str++;
	}
	tab[word] = 0;
	return (tab);
}
