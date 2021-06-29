/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 04:09:19 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 04:11:52 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_info *info)
{
	int tem;

	write(1, "rr\n", 3);
	if (!empty_dq(info->a))
	{
		tem = top_dq(info->a);
		push_bottom_dq(tem, info->a);
		top_pop_dq(info->a);
		info->total_count++;
	}
	if (!empty_dq(info->b))
	{
		push_bottom_dq(top_dq(info->b), info->b);
		top_pop_dq(info->b);
		info->total_count++;
	}
	info->total_count++;
}

void	rev_rotate_a(t_info *info)
{
	int val;

	write(1, "rra\n", 4);
	if (!empty_dq(info->a))
	{
		val = bottom_dq(info->a);
		bottom_pop_dq(info->a);
		push_top_dq(val, info->a);
		info->total_count++;
	}
}

void	rev_rotate_b(t_info *info)
{
	int val;

	write(1, "rrb\n", 4);
	if (!empty_dq(info->b))
	{
		val = bottom_dq(info->b);
		bottom_pop_dq(info->b);
		push_top_dq(val, info->b);
		info->total_count++;
	}
}

void	rrr(t_info *info)
{
	int val;

	write(1, "rrr\n", 4);
	if (!empty_dq(info->a))
	{
		val = bottom_dq(info->a);
		bottom_pop_dq(info->a);
		push_top_dq(val, info->a);
		info->total_count++;
	}
	if (!empty_dq(info->b))
	{
		val = bottom_dq(info->b);
		bottom_pop_dq(info->b);
		push_top_dq(val, info->b);
		info->total_count++;
	}
	info->total_count++;
}
