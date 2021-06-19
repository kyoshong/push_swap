/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/18 12:06:32 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pop_top_dq(t_dq *dq)
{
	if (dq->arr[dq->top] != NULL)
	{
		dq->arr[dq->top] = NULL;
		dq->top = dq->top - 1;
	}
}

int		bottom_dq(t_dq *dq)
{
	return (dq->arr[dq->bottom]);
}

int		at_dq(int val, t_dq *dq)
{
	return (dq->arr[val]);
}
