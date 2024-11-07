/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:17:37 by teando            #+#    #+#             */
/*   Updated: 2024/11/07 17:25:37 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

unsigned int	ft_abs(int n);
int				ft_atoi(const char *str);
long			ft_atol(const char *nptr);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_utoa(unsigned int n);

#endif