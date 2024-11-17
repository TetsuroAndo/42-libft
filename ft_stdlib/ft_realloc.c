/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:51:06 by teando            #+#    #+#             */
/*   Updated: 2024/11/17 22:21:14 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;

	if (!ptr)
	{
		new_ptr = malloc(size);
		if (new_ptr)
			ft_bzero(new_ptr, size);
		return (new_ptr);
	}
	if(!size)
		return (free(ptr), NULL);
	old_size = ft_strlen(ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size < size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
