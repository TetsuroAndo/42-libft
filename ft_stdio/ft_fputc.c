/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:23:08 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 20:41:54 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdio.h>

int	ft_fputc(int c, FILE *stream)
{
	unsigned char	uc;

	if (stream == NULL)
		return (EOF);
	uc = (unsigned char)c;
	if (fwrite(&uc, sizeof(char), 1, stream) != 1)
		return (EOF);
	return ((int)uc);
}
