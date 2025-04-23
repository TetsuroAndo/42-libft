/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:48 by teando            #+#    #+#             */
/*   Updated: 2025/04/23 16:11:54 by teando           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_lst.h"
#include "ft_stdio.h"

static void	put_hex_fd(unsigned long n, int fd)
{
	const char	hex[17] = "0123456789abcdef";
	char		buf[sizeof(unsigned long) * 2 + 1];
	int			i;

	i = 0;
	if (n == 0)
	{
		ft_dprintf(fd, "0");
		return ;
	}
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
		ft_dprintf(fd, &buf[i]);
}

void	ft_gc_dump(const t_list *gc, int fd)
{
	size_t	idx;
	t_list	*cur;

	idx = 0;
	if (!gc)
	{
		ft_dprintf(fd, "(gc=NULL)\n");
		return ;
	}
	cur = gc->next;
	while (cur)
	{
		ft_dprintf(fd, "[");
		put_hex_fd(idx++, fd);
		ft_dprintf(fd, "] node=0x");
		put_hex_fd((unsigned long)cur, fd);
		ft_dprintf(fd, " data=0x");
		put_hex_fd((unsigned long)cur->data, fd);
		ft_dprintf(fd, "\n");
		cur = cur->next;
	}
}
