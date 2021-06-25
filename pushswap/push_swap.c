/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/25 16:38:42 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	div_pivot_a(int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = s_arr[len - 1];
	p2 = s_arr[len - (len / 6)];
	i = 0;
	while (i < len / 3)
	{
		if (top_dq(a) == p1 && top_dq(a) == p2)
			rotate_a();
		else
		{
			push_b();
			if (top_dq(b) > p2)
				rotate_b();
		}
		i++;
	}
}

void	div_pivot_b(int len)
{
	int i;
	int p1;
	
	p1 = s_arr[len];
	i = 0;
	while (i < len)
	{
		if (top_dq(a) >= p1)
			rotate_a();
		else
		{
			push_b();
			if (top_dq(a) >= p1 && top_dq(b) >= (p1 / 2))
				rr();
			else if (top_dq(b) >= (p1 / 2))
				rotate_b();
		}
		i++;
	}
}

void	div_pivot(int len)
{
	int i;
	int p1;

	p1 = s_arr[len / 3];
	i = 0;
	while (i < len)
	{
		if (top_dq(a) >= p1)
			rotate_a();
		else
		{
			push_b();
			if (top_dq(a) >= p1 && top_dq(b) >= (p1 / 2))
				rr();
			else if (top_dq(b) >= (p1 / 2))
				rotate_b();
		}
		i++;
	}
	div_pivot_b((len / 3) * 2);
	div_pivot_a(len);
}

void	sort_pivot2(int big, int small)
{
	int i;
	int limit;

	i = 0;
	limit = small;
	while (big >= small)
	{
		i = find_short(limit, big--, small++);
		if (i == 1)
			move_top(big, 0, 0);
		else if (i == 2)
			move_top(big--, 0, 1);
		else if (i == 3)
			move_top(small, 1, 0);
		else if (i == 4)
			move_top(small++, 1, 1);
		else if (i == 5)
			move_bottom(small, 1, 0);
		else if (i == 6)
			move_bottom(small++, 1, 1);
		else if (i == 7)
			move_bottom(big, 0, 0);
		else if (i == 8)
			move_bottom(big--, 0, 1);
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
