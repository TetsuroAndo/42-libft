/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:17:34 by teando            #+#    #+#             */
/*   Updated: 2024/12/17 22:35:23 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include "ft_printf.h"
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putchar(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putstrs_fd(char **strs, char *delimiter, int fd);

#endif