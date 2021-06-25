/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:34:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/25 22:40:29 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		max_val(int min, int count, int n, int result)
{
	if (min > 0 && min < count)
		return (result);
	else
		return (n);
}

int		find_short_top(int *min, int limit, int big, int small)
{
	int i;
	int count;
	int result;
	
	i = b->top;
	count = 1;
	result = 0;
	while (!empty_dq(b) && top_dq(b) >= s_arr[limit])
	{
		if (b->arr[i] == s_arr[big])
			if ((result = max_val(*min, count, 1, result)))
				*min = count;
		if (b->arr[i] == s_arr[big - 1])
			if ((result = max_val(*min, count + 1, 2, result)))
				*min = count + 1;
		if (b->arr[i] == s_arr[small])
			if ((result = max_val(*min, count + 2, 3, result)))
				*min = count + 2;
		if (b->arr[i] == s_arr[small + 1])
			if ((result = max_val(*min, count + 3, 4, result)))
				*min = count + 3;
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
	result = 0;
	while (!empty_dq(b) && bottom_dq(b) >= s_arr[limit])
	{
		if (b->arr[j] == s_arr[small])
			if ((result = max_val(*min, count + 4, 5, result)))
				*min = count + 4;
		if (b->arr[j] == s_arr[small + 1])
			if ((result = max_val(*min, count + 5, 8, result)))
				*min = count + 5;
		if (b->arr[j] == s_arr[big])
			if ((result = max_val(*min, count + 2, 6, result)))
				*min = count + 2;
		if (b->arr[j] == s_arr[big - 1])
			if ((result = max_val(*min, count + 3, 7, result)))
				*min = count + 3;
		j++;
		count++;
	}
	return (result);
}

int		find_short(int limit, int big, int small)
{
	int b_min;
	int t_min;
	int b_result;
	int t_result;
	
	t_min = 0;
	b_min = 0;
	t_result = find_short_top(&t_min, limit, big, small);
	b_result = find_short_bottom(&b_min, limit, big, small);
	if (t_min > b_min)
		return (b_result);
	else
		return (t_result);
}