/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/24 17:18:09 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	 div_pivot_a(int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = s_arr[len - 1];
	p2 = s_arr[(len / 9) * 7];
	i = 0;
	while (i < len / 3)
	{
		if (top_dq(a) < p1 && top_dq(a) > p2)
			push_b();
		else if (top_dq(a) <= p2 && top_dq(a) != s_arr[(len / 3) * 2])
		{
			push_b();
			rotate_b();
		}
		else
			rotate_a();
		i++;
	}
}

void	div_pivot(int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = s_arr[(len / 3) * 2];
	p2 = s_arr[len / 3];
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
	div_pivot_a(len);
}

void	sort_pivot2(int big, int small)
{
	int i;
	int limit;

	i = 0;
	limit = small;
	while (i = find_short(limit, big--, small++))
	{
		if (i == 1)
			find_val_top(big, small, 0);
		else if (i == 2)
			find_val_bottom(big, small, 0);
		else if (i == 3)
			find_val_top(big - 1, small + 1, 1);
		else if (i == 4)
			find_val_bottom(big - 1, small + 1, 1);
	}
	
}

void	sort_pivot(int len)
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
		sort_pivot2(top, bottom);
		i--;
	}
}

void	push_swap(int len)
{
	div_pivot(len);
	sort_pivot(len);
}
