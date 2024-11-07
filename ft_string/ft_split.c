/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:07:27 by teando            #+#    #+#             */
/*   Updated: 2024/11/07 17:32:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_nsplit(const char *s, char c, size_t len)
{
	char	**r;
	char	**r_head;

	r_head = (char **)ft_calloc(len + 1, sizeof(char *));
	r = r_head;
	while (r_head && len--)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		*r = (char *)s;
		while (*s && *s != c)
			s++;
		*r = ft_substr(*r, 0, s - *r);
		if (!*r++)
		{
			while (r_head <= r - 1)
				free(*(--r - 1));
			free(r_head);
			return (NULL);
		}
	}
	return (r_head);
}

char	**ft_split(char const *s, char c)
{
	return (ft_nsplit(s, c, count_words(s, c)));
}
