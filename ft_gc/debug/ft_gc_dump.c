/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:48 by teando            #+#    #+#             */
/*   Updated: 2025/04/23 15:26:08 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <unistd.h>

static void	put_hex_fd(unsigned long n, int fd)
{
	const char	hex[17] = "0123456789abcdef";
	char		buf[sizeof(unsigned long) * 2 + 1];
	int			i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
		write(fd, &buf[i], 1);
}

void	ft_gc_debug(const t_list *gc, int fd)
{
	size_t	idx;
	t_list	*cur;

	idx = 0;
	if (!gc)
	{
		write(fd, "(gc=NULL)\n", 10);
		return ;
	}
	cur = gc->next;
	while (cur)
	{
		write(fd, "[", 1);
		put_hex_fd(idx++, fd);
		write(fd, "] node=0x", 9);
		put_hex_fd((unsigned long)cur, fd);
		write(fd, " data=0x", 8);
		put_hex_fd((unsigned long)cur->data, fd);
		write(fd, "\n", 1);
		cur = cur->next;
	}
}
