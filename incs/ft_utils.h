/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:55 by teando            #+#    #+#             */
/*   Updated: 2024/12/19 02:17:10 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

char	*ft_substr_r(const char *str, char delimiter);
char	*ft_substr_l(const char *str, char delimiter);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	**ft_strs_dup(char **ss);
void	ft_swap(char *a, char *b);

#endif