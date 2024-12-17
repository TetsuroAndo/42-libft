/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_from_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:29:42 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 21:23:27 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

t_list	*ft_list_from_strs(char **strs)
{
	t_list	*list;
	t_list	*new;

	if (!strs)
		return (NULL);
	list = 0;
	while (*strs)
	{
		new = ft_create_elem(*strs);
		if (!new)
			return (ft_lstclear(&list, free), NULL);
		new->next = list;
		list = new;
		strs++;
	}
	return (list);
}
