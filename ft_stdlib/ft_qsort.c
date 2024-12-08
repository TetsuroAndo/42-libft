/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:34:37 by teando            #+#    #+#             */
/*   Updated: 2024/12/09 07:34:38 by teando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

static void	qsort_swap(void *x, void *y, size_t size)
{
	size_t			i;
	unsigned char	*px;
	unsigned char	*py;
	unsigned char	temp;

	if (x == y)
		return ;
	px = (unsigned char *)x;
	py = (unsigned char *)y;
	i = 0;
	while (i < size)
	{
		temp = px[i];
		px[i] = py[i];
		py[i] = temp;
		i++;
	}
}

static void	*median_of_three(char *a, char *b, char *c,
		int (*compar)(const void *, const void *))
{
	if (compar((const void *)a, (const void *)b) < 0)
	{
		if (compar((const void *)b, (const void *)c) < 0)
			return (b);
		else if (compar((const void *)a, (const void *)c) < 0)
			return (c);
		else
			return (a);
	}
	else
	{
		if (compar((const void *)b, (const void *)c) > 0)
			return (b);
		else if (compar((const void *)a, (const void *)c) < 0)
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
		while (i < nmemb && compar((const void *)(base + i * size),
				(const void *)pivot) < 0)
			i++;
		while (j > 0 && compar((const void *)(base + j * size),
				(const void *)pivot) > 0)
			j--;
		if (i >= j)
			break ;
		qsort_swap(base + i * size, base + j * size, size);
		i++;
		j--;
	}
	qsort_swap(base, base + j * size, size);
	return (j);
}

static size_t	partition(char *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	void	*pivot;
	size_t	p;

	pivot = median_of_three(base, base + (nmemb / 2) * size, base + (nmemb - 1)
			* size, compar);
	qsort_swap(base, pivot, size);
	pivot = (void *)base;
	p = part_loop(base, nmemb, size, compar, (char *)pivot);
	return (p);
}

void	ft_qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *))
{
	size_t	p;
	char	*arr;

	if (nmemb <= 1 || size == 0)
		return ;
	arr = (char *)base;
	p = partition(arr, nmemb, size, compar);
	if (p > 0)
		ft_qsort(arr, p, size, compar);
	ft_qsort(arr + (p + 1) * size, nmemb - p - 1, size, compar);
}
