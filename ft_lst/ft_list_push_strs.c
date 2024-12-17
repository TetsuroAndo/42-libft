/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:29:42 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 20:43:42 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lst.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	int i;
	t_list *list;
	t_list *new;

	list = 0;
	i = 0;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		if (new)
		{
			new->next = list;
			list = new;
		}
		i++;
	}
	return (list);
}
