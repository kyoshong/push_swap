/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:41:24 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/23 23:15:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		find_short(int *arr, int limit, int val, int val2)
{
	int i;
	int j;

	i = b->top;
	j = b->bottom;
	while (!empty_dq(b) && (top_dq(b) >= arr[limit] || bottom_dq(b) >= arr[limit]))
	{
		if (b->arr[i] == arr[val] || b->arr[i] == arr[val2])
			find_val_top(arr, val, val2, 0);
		if (b->arr[j] == arr[val2] || b->arr[j] == arr[val])
			find_val_bottom(arr, val, val2, 0);
		if (b->arr[i] == arr[val - 1] || b->arr[i] == arr[val2 + 1])
			find_val_top(arr, val - 1, val2 + 1, 1);
		if ( b->arr[j] == arr[val - 1] || b->arr[j] == arr[val2 + 1])
			find_val_bottom(arr, val - 1, val2 + 1, 1);
		i--;
		j++;
	}
}

int		find_val_top(int *arr, int val, int val2, int next_val)
{
	int tem;
	
	while (1)
	{
		if (top_dq(b) == arr[val])
		{
			tem = val;
			push_a();
			break ;
		}
		if (val2 > -1 && top_dq(b) == arr[val2])
		{
			tem = val;
			push_a();
			break ;
		}
		rotate_b();
	}
	if (next_val)
	{
		find_one_val(arr, tem);
	}
	return (count);
}

int		find_val_bottom(int *arr, int val, int val2, int next_val)
{
	int tem;
	
	while (1)
	{
		if (top_dq(b) == arr[val])
		{
			tem = val;
			push_a();
			break ;
		}
		if (val2 > -1 && top_dq(b) == arr[val2])
		{
			tem = val2;
			push_a();
			break ;
		}
		rev_rotate_b();
	}
	if (next_val)
		find_one_val(arr, tem);
	return (count);
}

int		find_one_val(int *arr, int val)
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
		if (b->arr[i] == arr[val])
		{
			find_val_top(arr, val, -1, 0);
			break ;
		}
		if (b->arr[j] == arr[val])
		{
			find_val_bottom(arr, val, -1, 0);
			break ;
		}
		i--;
		j++;
	}
	return (result);
}
