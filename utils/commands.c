/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:07:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 04:06:53 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_info *info)
{
	int tem;

	write(1, "sa\n", 3);
	tem = info->a->arr[info->a->top];
	info->a->arr[info->a->top] = info->a->arr[size_dq(info->a) - 1];
	info->a->arr[size_dq(info->a) - 1] = tem;
	info->total_count++;
}

void	swap_b(t_info *info)
{
	int tem;

	write(1, "sb\n", 3);
	tem = info->b->arr[info->b->top];
	info->b->arr[info->b->top] = info->b->arr[size_dq(info->b) - 1];
	info->b->arr[size_dq(info->b) - 1] = tem;
	info->total_count++;
}

void	ss(t_info *info)
{
	int tem;

	write(1, "ss\n", 3);
	tem = info->a->arr[info->a->top];
	info->a->arr[info->a->top] = info->a->arr[size_dq(info->a) - 1];
	info->a->arr[size_dq(info->a) - 1] = tem;
	info->total_count++;
	tem = info->b->arr[info->b->top];
	info->b->arr[info->b->top] = info->b->arr[size_dq(info->b) - 1];
	info->b->arr[size_dq(info->b) - 1] = tem;
	info->total_count++;
	info->total_count++;
}
