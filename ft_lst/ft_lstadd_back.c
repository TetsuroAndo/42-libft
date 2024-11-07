/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:09:45 by teando            #+#    #+#             */
/*   Updated: 2024/11/07 16:58:18 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
