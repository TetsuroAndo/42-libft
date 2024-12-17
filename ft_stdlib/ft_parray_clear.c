/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parray_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:19 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 16:26:13 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_parray_clear(void *ptr)
{
	char	**array;
	size_t	i;

	i = 0;
	array = (char **)ptr;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}
