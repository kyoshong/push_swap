/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:12:02 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 02:30:30 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_top(t_info *info, int val, int rotate, int next_val)
{
	int tem;
	
	if (next_val && rotate)
		tem = val - 1;
	else if (next_val)
		tem = val + 1;
	else
		tem = val;
	int i = 0;
	while (i < info->s_len)
	{
		if (top_dq(info->b) == info->s_arr[tem])
			break ;
		rotate_b(info);
		i++;
	}
	push_a(info);
	if (next_val)
	{
		find_one_val(info, val);
		swap_a(info);
		if (rotate)
			rotate_a(info);
	}
	if (rotate)
		rotate_a(info);
}

void	move_bottom(t_info *info, int val, int rotate, int next_val)
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
		if (top_dq(info->b) == info->s_arr[tem])
			break ;
		rev_rotate_b(info);
	}
	push_a(info);
	if (next_val)
	{
		find_one_val(info, val);
		swap_a(info);
		if (rotate)
			rotate_a(info);
	}
	if (rotate)
		rotate_a(info);
}

void	find_one_val(t_info *info, int val)
{
	int i;
	int j;

	i = info->b->top;
	j = info->b->bottom;
	while (1)
	{
		if (info->b->arr[i] == info->s_arr[val])
		{
			move_top(info, val, 0, 0);
			break ;
		}
		if (info->b->arr[j] == info->s_arr[val])
		{
			move_bottom(info, val, 0, 0);
			break ;
		}
		i--;
		j++;
	}
}
