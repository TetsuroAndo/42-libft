/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:55:09 by teando            #+#    #+#             */
/*   Updated: 2024/10/25 01:47:21 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*head;

	head = s;
	while (*s && maxlen--)
		s++;
	return (s - head);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*r;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strnlen(s, n);
	r = (char *)malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[len] = '\0';
	return (ft_memcpy(r, s, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	return (ft_strndup(s + ft_strnlen(s, start), len));
}
