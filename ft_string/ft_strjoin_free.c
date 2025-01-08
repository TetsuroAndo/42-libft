/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 05:10:13 by teando            #+#    #+#             */
/*   Updated: 2025/01/09 05:14:05 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_string.h"
#include <stdlib.h>

char *ft_strjoin_free(char const *s1, char const *s2)
{
    char *str;

    if (!s1 || !s2)
        return (NULL);
    str = ft_strjoin(s1, s2);
    if (s1)
        free((void *)s1);
    if (s2)
        free((void *)s2);
    return (str);
}
