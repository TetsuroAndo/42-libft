/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:23:51 by teando            #+#    #+#             */
/*   Updated: 2025/04/25 20:59:30 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_gc.h"
#include <stdlib.h>

void	ft_gc_free(t_list *gc, void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	ft_gc_untrack(gc, *ptr);
}
