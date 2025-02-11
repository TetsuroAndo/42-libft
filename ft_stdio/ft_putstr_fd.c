/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:22:15 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 22:35:12 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdio.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (ft_putchar_fd(*s++, fd) == -1)
			return (EOF);
		count++;
	}
	return (count);
}
