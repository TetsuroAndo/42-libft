/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 05:27:16 by teando            #+#    #+#             */
/*   Updated: 2024/11/16 05:27:17 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (ft_strchr(reject, s[i]))
			break ;
	}
	return (i);
}
