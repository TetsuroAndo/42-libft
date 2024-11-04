/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:23:32 by teando            #+#    #+#             */
/*   Updated: 2024/11/04 22:09:21 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stddef.h>
#include <stdio.h>

int	ft_putnbr(int n)
{
	char			buffer[12];
	unsigned int	num;
	char			*c;
	int				count;

	num = n ^ ((n >> 31) & ((unsigned int)(-n - n)));
	c = &buffer[12];
	*--c = '\0';
	while (num || !*c)
	{
		*--c = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*--c = '-';
	count = 0;
	while (*c)
	{
		if (ft_putchar(*c++) == EOF)
			return (EOF);
		count++;
	}
	return (count);
}
