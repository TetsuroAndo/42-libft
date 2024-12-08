/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:55 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 06:07:45 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_nswap(char *a, char *b, size_t size);
void	ft_swap(char *a, char *b);

#endif