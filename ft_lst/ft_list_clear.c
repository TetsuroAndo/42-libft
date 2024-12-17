/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:29:42 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 21:02:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;

	current = begin_list;
	while (current)
	{
		tmp = current->next;
		(*free_fct)(current->data);
		free(current);
		current = tmp;
	}
}
