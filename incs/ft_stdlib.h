/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:17:37 by teando            #+#    #+#             */
/*   Updated: 2024/10/20 02:26:03 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
#define FT_STDLIB_H

#include <stddef.h>

void *ft_calloc(size_t count, size_t size);

int ft_atoi(const char *str);
char *ft_itoa(int n);

#endif