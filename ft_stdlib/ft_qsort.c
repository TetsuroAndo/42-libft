/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 05:53:45 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 05:56:00 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

static void	*median_of_three(char *a, char *b, char *c,
		int (*compar)(const void *, const void *))
{
	if (compar(a, b) < 0)
	{
		if (compar(b, c) < 0)
			return (b);
		else if (compar(a, c) < 0)
			return (c);
		else
			return (a);
	}
	else
	{
		if (compar(b, c) > 0)
			return (b);
		else if (compar(a, c) < 0)
			return (a);
		else
			return (c);
	}
}

static size_t	part_loop(char *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *), char *pivot)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = nmemb - 1;
	while (1)
	{
		while (i < nmemb && compar(base + i * size, pivot) < 0)
			i++;
		while (j > 0 && compar(base + j * size, pivot) > 0)
			j--;
		if (i >= j)
			break ;
		ft_nswap(base + i * size, base + j * size, size);
		i++;
		j--;
	}
	ft_nswap(base, base + j * size, size);
	return (j);
}

static size_t	partition(char *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	char	*pivot;

	pivot = median_of_three(base, base + (nmemb / 2) * size, base + (nmemb - 1)
			* size, compar);
	ft_nswap(base, pivot, size);
	pivot = base;
	return (part_loop(base, nmemb, size, compar, pivot));
}

static void	ft_qsort_internal(char *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	size_t	p;

	if (nmemb <= 1)
		return ;
	p = partition(base, nmemb, size, compar);
	if (p > 0)
		ft_qsort_internal(base, p, size, compar);
	ft_qsort_internal(base + (p + 1) * size, nmemb - p - 1, size, compar);
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	if (nmemb <= 1 || size == 0)
		return ;
	ft_qsort_internal((char *)base, nmemb, size, compar);
}
