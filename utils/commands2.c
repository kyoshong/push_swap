/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:39:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 04:06:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_info *info)
{
	write(1, "pa\n", 3);
	if (!empty_dq(info->b))
	{
		push_top_dq(top_dq(info->b), info->a);
		top_pop_dq(info->b);
		info->total_count++;
	}
}

void	push_b(t_info *info)
{
	write(1, "pb\n", 3);
	if (!empty_dq(info->a))
	{
		info->b->top = info->b->top + 1;
		info->b->arr[info->b->top] = top_dq(info->a);
		top_pop_dq(info->a);
		info->total_count++;
	}
}

void	rotate_a(t_info *info)
{
	int tem;

	write(1, "ra\n", 3);
	if (!empty_dq(info->a))
	{
		tem = top_dq(info->a);
		push_bottom_dq(tem, info->a);
		top_pop_dq(info->a);
		info->total_count++;
	}
}

void	rotate_b(t_info *info)
{
	write(1, "rb\n", 3);
	if (!empty_dq(info->b))
	{
		push_bottom_dq(top_dq(info->b), info->b);
		top_pop_dq(info->b);
		info->total_count++;
	}
}
