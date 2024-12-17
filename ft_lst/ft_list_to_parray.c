/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_parray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:32:18 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 17:58:57 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdlib.h>

char	**ft_list_to_parray(t_list *lst)
{
	size_t	len;
	size_t	i;
	char	**array;

	if (!lst)
	{
		array = (char **)ft_calloc(sizeof(char *), 1);
		if (!array)
			return (NULL);
		array[0] = NULL;
		return (array);
	}
	len = ft_lstsize(lst);
	array = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (lst)
	{
		array[i] = ft_strdup((char *)lst->data);
		if (!array[i++])
			return (ft_parray_clear(array), NULL);
		lst = lst->next;
	}
	return (array);
}
