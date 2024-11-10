/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:17:34 by teando            #+#    #+#             */
/*   Updated: 2024/11/10 11:09:16 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include "ft_printf.h"
# include <unistd.h>

// int		ft_fputc(int c, FILE *stream);
// int		ft_fputs(const char *s, FILE *stream);
// int		ft_putc(int c, FILE *stream);
int		ft_putchar_fd(char c, int fd);
int		ft_putchar(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// int		ft_puts(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif