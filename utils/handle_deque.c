/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:30 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 02:24:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_a(int size, t_info *info)
{
	int		*arr;
	int		i;

	if (!(info->a = (t_dq *)malloc(sizeof(*info->a))))
		return ;
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(info->a);
		return ;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = info->s_arr[size - i -1];
		i++;
	}
	arr[size] = 0;
	arr[size + 1] = 0;
	info->a->arr = arr;
	info->a->top = size - 1;
	info->a->bottom = 0;
}

void	init_b(int size, t_info *info)
{
	int		*arr;
	int		i;

	if (!(info->b = (t_dq *)malloc(sizeof(*info->b))))
		return ;
	if (!(arr = (int *)malloc(sizeof(int) * (size + 1))))
	{
		free(info->b);
		return ;
	}
	i = 0;
	while (i < size + 2)
		arr[i++] = 0;
	info->b->arr = arr;
	info->b->top = -1;
	info->b->bottom = 0;
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
		push_top_dq(val, dq);
	else
	{
		dq->top = dq->top + 1;
		i = dq->top;
		while (0 <= i)
		{
			dq->arr[i + 1] = dq->arr[i];
			i--;
		}
		dq->arr[dq->bottom] = val;
	}
}
