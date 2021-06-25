/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:12:02 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/25 22:27:17 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	move_top(int val, int rotate, int next_val)
{
	int tem;
	
	if (next_val && rotate)
		tem = val - 1;
	else if (next_val)
		tem = val + 1;
	else
		tem = val;
	while (1)
	{
		if (top_dq(b) == s_arr[tem])
			break ;
		rotate_b();
	}
	push_a();
	if (next_val)
	{
		find_one_val(val);
		swap_a();
		if (rotate)
			rotate_a();
	}
	if (rotate)
		rotate_a();
}

void	move_bottom(int val, int rotate, int next_val)
{
	int tem;
	
	if (next_val && rotate)
		tem = val - 1;
	else if (next_val)
		tem = val + 1;
	else
		tem = val;
	while (1)
	{
		if (top_dq(b) == s_arr[tem])
			break ;
		rev_rotate_b();
	}
	push_a();
	if (next_val)
	{
		find_one_val(val);
		swap_a();
		if (rotate)
			rotate_a();
	}
	if (rotate)
		rotate_a();
}

void	find_one_val(int val)
{
	int count;
	int result;
	int i;
	int j;

	result = 0;
	i = b->top;
	j = b->bottom;
	count = 0;
	while (1)
	{
		count++;
		if (b->arr[i] == s_arr[val])
		{
			move_top(val, 0, 0);
			break ;
		}
		if (b->arr[j] == s_arr[val])
		{
			move_bottom(val, 0, 0);
			break ;
		}
		i--;
		j++;
	}
}
