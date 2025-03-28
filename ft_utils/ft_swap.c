/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:51:10 by teando            #+#    #+#             */
/*   Updated: 2024/12/10 05:32:28 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char	tmp;

	if (a == b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
