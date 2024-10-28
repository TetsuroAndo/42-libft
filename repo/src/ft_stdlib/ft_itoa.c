/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:09:55 by teando            #+#    #+#             */
/*   Updated: 2024/10/23 23:05:25 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_itoa(int n)
{
	char			buffer[12];
	unsigned int	num;
	char			*c;

	c = &buffer[12];
	*--c = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (num || !*c)
	{
		*--c = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*--c = '-';
	return (ft_strdup(c));
}
