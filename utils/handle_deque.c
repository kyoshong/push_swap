/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:30 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/18 12:05:21 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	init_a(int *val, int size)
{
	int		*arr;
	int		i;

	if (!(a = (t_dq *)malloc(sizeof(*a))))
		return (NULL);
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(a);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = val[size - i - 1];
		i++;
	}
	a->arr = arr;
	a->top = size;
	a->bottom = 0;
	return (a);
}

void	init_b(int size)
{
	int		*arr;
	int		i;

	if (!(b = (t_dq *)malloc(sizeof(*b))))
		return (NULL);
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(b);
		return (NULL);
	}
	i = 0;
	while (i < size + 1)
		arr[i++] = NULL;
	b->arr = arr;
	b->top = size;
	b->bottom = 0;
}

int		empty_dq(t_dq *dq)
{
	if (dq->bottom > dq->top)
		return (1);
	else
		return (0);
}

void	push_bottom_dq(int val, t_dq *dq)
{
	dq->arr[dq->bottom + 1] = val;
	dq->bottom = dq->bottom + 1;
}
