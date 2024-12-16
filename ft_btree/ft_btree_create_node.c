/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:30:47 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 07:30:48 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *node;

    node = (t_btree *)malloc(sizeof(t_btree));
    if (node)
    {
        node->item = item;
        node->left = 0;
        node->right = 0;
    }
    return (node);
}
