/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:30 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/25 21:59:58 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	init_a(int size)
{
	int		*arr;
	int		i;

	if (!(a = (t_dq *)malloc(sizeof(*a))))
		return ;
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(a);
		return ;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = s_arr[size - i - 1];
		i++;
	}
	a->arr = arr;
	a->top = size - 1;
	a->bottom = 0;
}

void	init_b(int size)
{
	int		*arr;
	int		i;

	if (!(b = (t_dq *)malloc(sizeof(*b))))
		return ;
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(b);
		return ;
	}
	i = 0;
	while (i < size + 2)
		arr[i++] = 0;
	b->arr = arr;
	b->top = -1;
	b->bottom = 0;
}

int		empty_dq(t_dq *dq)
{
	if (dq->top == -1)
		return (1);
	else
		return (0);
}

void	push_top_dq(int val, t_dq *dq)
{
	dq->top = dq->top + 1;
	dq->arr[dq->top] = val;
}

void	push_bottom_dq(int val, t_dq *dq)
{
	int i;

	if (empty_dq(dq))
	{
		push_top_dq(val, dq);
	}
	else
	{
		dq->top = dq->top + 1;
		i = dq->bottom;
		while (dq->top > i)
		{
			dq->arr[i + 1] = dq->arr[i];
			i++;
		}
		dq->arr[dq->bottom] = val;
	}
}
