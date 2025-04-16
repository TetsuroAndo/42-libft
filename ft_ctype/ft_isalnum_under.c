/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_under.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:41 by teando            #+#    #+#             */
/*   Updated: 2025/04/17 08:28:17 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_ctype.h"

int	ft_isalnum_under(int c)
{
	return (ft_isalnum(c) || c == '_');
}
