/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:16:18 by teando            #+#    #+#             */
/*   Updated: 2024/10/23 23:05:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[12];
	unsigned int	num;
	char			*c;

	if (n < 0)
		num = -n;
	else
		num = n;
	c = &buffer[12];
	*--c = '\0';
	while (num || !*c)
	{
		*--c = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*--c = '-';
	ft_putstr_fd(c, fd);
}
