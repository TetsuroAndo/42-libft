/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:30:20 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 07:30:32 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_btree.h"

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return;
    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}
