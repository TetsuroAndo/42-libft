#include "ft_btree.h"

void ft_btree_clear(t_btree **root, void (*del)(void *))
{
    if (!root || !del || !*root)
        return ;
    ft_btree_clear(&(*root)->left, del);
    ft_btree_clear(&(*root)->right, del);
    del((*root)->item);
    free(*root);
    *root = NULL;
}
