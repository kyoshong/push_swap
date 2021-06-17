/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:30 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 15:49:46 by hyospark         ###   ########.fr       */
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
	a->front = size;
	a->back = 0;
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
	b->front = size;
	b->back = 0;
}

t_dq	empty_dq()
{
	
}

t_dq	push_back_dq()
{
	
}
