/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:51:10 by teando            #+#    #+#             */
/*   Updated: 2025/04/29 20:04:41 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapint(int **a, int **b)
{
	int	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
