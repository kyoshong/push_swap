/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:34:41 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/26 17:49:28 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		max_val(int min, int count, int n, int result)
{
	if (min > 0 && min < count)
		return (result);
	else
		return (n);
}

int		find_short_top(t_info *info, int limit, int big, int small)
{
	int i;
	int count;
	int result;
	
	i = info->b->top;
	count = 1;
	info->find_min_t = 0;
	result = 0;
	while (!empty_dq(info->b) && top_dq(info->b) >= info->s_arr[limit])
	{
		if (info->b->arr[i] == info->s_arr[big])
			if ((result = max_val(info->find_min_t, count, 1, result)))
				info->find_min_t = count;
		if (info->b->arr[i] == info->s_arr[big - 1])
			if ((result = max_val(info->find_min_t, count + 1, 2, result)))
				info->find_min_t = count + 1;
		if (info->b->arr[i] == info->s_arr[small])
			if ((result = max_val(info->find_min_t, count + 2, 3, result)))
				info->find_min_t = count + 2;
		if (info->b->arr[i] == info->s_arr[small + 1])
			if ((result = max_val(info->find_min_t, count + 3, 4, result)))
				info->find_min_t = count + 3;
		i--;
		count++;
	}
	return (result);
}

int		find_short_bottom(t_info *info, int limit, int big, int small)
{
	int j;
	int result;
	int count;

	j = info->b->bottom;
	count = 1;
	info->find_min_b = 0;
	result = 0;
	while (!empty_dq(info->b) && bottom_dq(info->b) >= info->s_arr[limit])
	{
		if (info->b->arr[j] == info->s_arr[small])
			if ((result = max_val(info->find_min_b, count + 4, 5, result)))
				info->find_min_b = count + 4;
		if (info->b->arr[j] == info->s_arr[small + 1])
			if ((result = max_val(info->find_min_b, count + 5, 8, result)))
				info->find_min_b = count + 5;
		if (info->b->arr[j] == info->s_arr[big])
			if ((result = max_val(info->find_min_b, count + 2, 6, result)))
				info->find_min_b = count + 2;
		if (info->b->arr[j] == info->s_arr[big - 1])
			if ((result = max_val(info->find_min_b, count + 3, 7, result)))
				info->find_min_b = count + 3;
		j++;
		count++;
	}
	return (result);
}

int		find_short(t_info *info, int limit, int big, int small)
{
	int t_result;
	int b_result;

	t_result = find_short_top(info, limit, big, small);
	b_result = find_short_bottom(info, limit, big, small);
	if (info->find_min_t > info->find_min_b)
		return (b_result);
	else
		return (t_result);
}