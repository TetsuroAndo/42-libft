/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:28:21 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 20:40:12 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdio.h>

int	ft_puts(const char *s)
{
	if (s == NULL)
	{
		if (ft_fputs("(null)\n", stdout) == EOF)
			return (EOF);
		return (0);
	}
	if (ft_fputs(s, stdout) == EOF)
		return (EOF);
	if (ft_fputc('\n', stdout) == EOF)
		return (EOF);
	return (0);
}
