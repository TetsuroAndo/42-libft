/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:22:37 by teando            #+#    #+#             */
/*   Updated: 2025/03/27 10:32:35 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_string.h"

char	*strtok_r(char *restrict s, const char *restrict sep, char **restrict p)
{
	if (!s && !*p)
		return (NULL);
	if (!s)
		s = *p;
	s += ft_strspn(s, sep);
	if (!*s)
		return (*p = 0);
	*p = s + ft_strcspn(s, sep);
	if (**p)
		*(*p)++ = 0;
	else
		*p = 0;
	return (s);
}
