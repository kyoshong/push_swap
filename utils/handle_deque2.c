/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/23 23:07:02 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	top_pop_dq(t_dq *dq)
{
	if (!empty_dq(dq))
	{
		dq->arr[dq->top] = NULL;
		dq->top = dq->top - 1;
	}
}

void	bottom_pop_dq(t_dq *dq)
{
	int i;

	if (!empty_dq(dq))
	{
		i = dq->bottom;
		while (dq->top > i)
		{
			dq->arr[i] = dq->arr[i + 1];
			i++;
		}
		dq->arr[dq->top] = NULL;
		dq->top = dq->top - 1;
	}
}

int		top_dq(t_dq *dq)
{
	return (dq->arr[dq->top]);
}

int		bottom_dq(t_dq *dq)
{
	return (dq->arr[dq->bottom]);
}

int		at_dq(int val, t_dq *dq)
{
	return (dq->arr[val]);
}

int		size_dq(t_dq *dq)
{
	return (dq->top - dq->bottom);
}