/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:41:24 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/24 17:16:08 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		max_val(int min, int count, int new, int result)
{
	if (min > 0 && min < count)
		return (result);
	else
		return (new);
}

int		find_short_top(int min, int limit, int big, int small)
{
	int i;
	int count;
	int result;
	
	i = b->top;
	count = 1;
	result = 0;
	min = 0;
	while (!empty_dq(b) && top_dq(b) >= s_arr[limit])
	{
		if (b->arr[i] == s_arr[big])
			if (result = max_val(min, count, 1, result))
				min = count;
		if (b->arr[i] == s_arr[big - 1])
			if (result = max_val(min, count + 1, 2, result))
				min = count;
		if (b->arr[i] == s_arr[small])
			if (result = max_val(min, count + 2, 3, result))
				min = count;
		if (b->arr[i] == s_arr[small + 1])
			if (result = max_val(min, count + 3, 4, result))
				min = count;
		i--;
		count++;
	}
	return (result);
}

int		find_short_bottom(int *min, int limit, int big, int small)
{
	int j;
	int result;
	int count;

	j = b->bottom;
	count = 0;
	while (!empty_dq(b) && bottom_dq(b) >= s_arr[limit])
	{
		if (b->arr[j] == s_arr[small])
			if (result = max_val(min, count + 3, 4, result))
				min = count;
		if (b->arr[j] == s_arr[big])
			if (result = max_val(min, count + 3, 4, result))
				min = count;
		if (b->arr[j] == s_arr[big - 1])
			if (result = max_val(min, count + 3, 4, result))
				min = count;
		if (b->arr[j] == s_arr[small + 1])
			if (result = max_val(min, count + 3, 4, result))
				min = count;
		j++;
		count++;
	}
	return (result);
}

int		find_val_top(int val, int val2, int next_val)
{
	int tem;
	int count;
	
	while (1)
	{
		if (top_dq(b) == s_arr[val])
		{
			tem = val;
			push_a();
			break ;
		}
		if (val2 > -1 && top_dq(b) == s_arr[val2])
		{
			tem = val;
			push_a();
			break ;
		}
		rotate_b();
	}
	if (next_val)
	{
		find_one_val(tem);
	}
	return (count);
}

int		find_val_bottom(int val, int val2, int next_val)
{
	int tem;
	int count;
	
	while (1)
	{
		if (top_dq(b) == s_arr[val])
		{
			tem = val;
			push_a();
			break ;
		}
		if (val2 > -1 && top_dq(b) == s_arr[val2])
		{
			tem = val2;
			push_a();
			break ;
		}
		rev_rotate_b();
	}
	if (next_val)
		find_one_val(tem);
	return (count);
}

int		find_one_val(int val)
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
			find_val_top(val, -1, 0);
			break ;
		}
		if (b->arr[j] == s_arr[val])
		{
			find_val_bottom(val, -1, 0);
			break ;
		}
		i--;
		j++;
	}
	return (result);
}
