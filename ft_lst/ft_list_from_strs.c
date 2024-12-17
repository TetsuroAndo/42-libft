/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_from_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:29:42 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 23:25:26 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

t_list	*ft_list_from_strs(char **strs)
{
	t_list	*list;
	t_list	*new;

	if (!strs || !*strs)
		return (NULL);
	list = NULL;
	while (*strs)
	{
		new = ft_create_elem(*strs);
		if (!new)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		strs++;
	}
	return (list);
}
