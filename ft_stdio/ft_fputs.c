/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:23:10 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 21:13:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdio.h>

int	ft_fputs(const char *s, FILE *stream)
{
	while (*s)
	{
		if (ft_fputc(*s, stream) == EOF)
			return (EOF);
		s++;
	}
	return (0);
}
