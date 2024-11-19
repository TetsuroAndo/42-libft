/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 05:27:14 by teando            #+#    #+#             */
/*   Updated: 2024/11/16 05:27:15 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_strchr(accept, s[i]))
			break ;
	}
	return (i);
}
