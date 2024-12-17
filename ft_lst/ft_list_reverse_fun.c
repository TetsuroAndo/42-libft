/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:31:35 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 20:44:12 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lst.h"

static int ft_list_size_local(t_list *begin_list)
{
	int count;
	t_list *cur;

	count = 0;
	cur = begin_list;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void ft_list_reverse_fun(t_list *begin_list)
{
	t_list *start;
	t_list *end;
	void *temp;
	int size;
	int i;
	int j;

	size = ft_list_size_local(begin_list);
	i = 0;
	while (i < size / 2)
	{
		j = -1;
		start = begin_list;
		end = begin_list;
		while (++j < i)
			start = start->next;
		j = -1;
		while (++j < size - i - 1)
			end = end->next;
		temp = start->data;
		start->data = end->data;
		end->data = temp;
		i++;
	}
}
