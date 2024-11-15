/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbrk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 05:27:18 by teando            #+#    #+#             */
/*   Updated: 2024/11/16 05:27:19 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stddef.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	while (*s)
	{
		if (ft_strchr(accept, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}
