/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 02:55:06 by teando            #+#    #+#             */
/*   Updated: 2024/10/25 01:47:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*head;

	head = s;
	while (*s && maxlen--)
		s++;
	return (s - head);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (dstsize > dst_len)
	{
		dst += dst_len;
		while (*src && dst_len < dstsize - 1)
			*dst++ = (dstsize--, *src++);
		*dst = '\0';
	}
	return (dst_len + src_len);
}
