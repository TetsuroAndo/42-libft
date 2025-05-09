/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:31:26 by teando            #+#    #+#             */
/*   Updated: 2025/04/29 20:07:27 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}
