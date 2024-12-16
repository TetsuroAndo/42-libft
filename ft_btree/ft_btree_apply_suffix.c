/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:30:56 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 07:31:38 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_btree.h"

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    applyf(root->item);
}