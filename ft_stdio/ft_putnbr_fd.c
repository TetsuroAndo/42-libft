/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:16:18 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 20:18:15 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[12];
	unsigned int	un;
	char			*c;

	c = &buffer[12];
	*--c = '\0';
	un = ft_abs(n);
	while (un || !*c)
	{
		*--c = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		*--c = '-';
	ft_putstr_fd(c, fd);
}
