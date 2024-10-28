/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:55:09 by teando            #+#    #+#             */
/*   Updated: 2024/10/25 15:54:20 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\v');
}

static long	ft_atol(const char *nptr)
{
	unsigned long	cutoff;
	int				neg;
	int				tmp;
	unsigned long	r;

	neg = 0;
	r = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		neg = *nptr++ == '-';
	cutoff = (unsigned long)LONG_MAX ^ -neg;
	while (ft_isdigit(*nptr))
	{
		r *= 10;
		tmp = *nptr++ - '0';
		if (r > cutoff || cutoff - r < (unsigned long)tmp)
			return (cutoff);
		r += tmp;
	}
	if (neg)
		return (-r);
	return (r);
}

int	ft_atoi(const char *nptr)
{
	return ((int)ft_atol(nptr));
}
