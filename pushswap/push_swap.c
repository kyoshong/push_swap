/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/23 23:16:05 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	 div_pivot_a(int *arr, int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = arr[len - 1];
	p2 = arr[(len / 9) * 7];
	i = 0;
	while (i < len / 3)
	{
		if (top_dq(a) < p1 && top_dq(a) > p2)
			push_b();
		else if (top_dq(a) <= p2 && top_dq(a) != arr[(len / 3) * 2])
		{
			push_b();
			rotate_b();
		}
		else
			rotate_a();
		i++;
	}
}

void	div_pivot(int *arr, int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = arr[(len / 3) * 2];
	p2 = arr[len / 3];
	i = 0;
	while (i < len)
	{
		if (top_dq(a) >= p1) 
			rotate_a();
		else if (top_dq(a) < p1 && top_dq(a) >= p2)
			push_b();
		else if (top_dq(a) < p2)
		{
			push_b();
			if (top_dq(a) >= p1)
				rr();
			else
				rotate_b();
		}
		i++;
	}
	div_pivot_a(arr, len);
}

void	sort_pivot2(int *arr, int top, int bottom)
{
	int i;
	int limit;

	i = 0;
	limit = bottom;
	while (bottom <= top)
	{
		find_short(arr, limit, top--, bottom++);
	}
	
}

void	sort_pivot(int *arr, int len)
{
	int top;
	int bottom;
	int div;
	int i;

	if (top_dq(a) < bottom_dq(a))
		swap_a();
	div = len / 3;
	bottom = len;
	i = 2;
	while (i >= 0)
	{
		top = bottom - 1;
		bottom = div * i;
		sort_pivot2(arr, top, bottom);
		i--;
	}
}

void	push_swap(int *arr, int len)
{
	div_pivot(arr, len);
	sort_pivot(arr, len);
}
