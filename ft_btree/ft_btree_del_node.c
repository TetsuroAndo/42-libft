#include "ft_btree.h"

void ft_btree_del_node(t_btree *node,void (*del)(void *))
{
    if (node)
    {
        del(node->item);
        free(node);
    }
}
