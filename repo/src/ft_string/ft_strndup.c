/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:04:07 by teando            #+#    #+#             */
/*   Updated: 2024/10/25 16:16:07 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*head;

	head = s;
	while (*s && maxlen--)
		s++;
	return (s - head);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*r;
	size_t	len;

	len = ft_strnlen(s, n);
	r = (char *)malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[len] = '\0';
	return (ft_memcpy(r, s, len));
}
