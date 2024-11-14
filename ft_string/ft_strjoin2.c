/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:54:03 by teando            #+#    #+#             */
/*   Updated: 2024/11/08 04:54:14 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	return (ft_strjoin(s1, s2));
}