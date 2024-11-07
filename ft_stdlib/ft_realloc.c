/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:51:06 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 04:08:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(size));
	new_ptr = NULL;
	if (size)
	{
		new_ptr = malloc(size);
		if (!new_ptr)
			return (NULL);
		ft_memcpy(new_ptr, ptr, size);
	}
	free(ptr);
	return (new_ptr);
}
