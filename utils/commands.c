/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:07:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 21:00:38 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//스택 a의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_a(t_info *info)
{
	write(1, "sa\n", 3);
	int tem = info->a->arr[info->a->top];
	info->a->arr[info->a->top] = info->a->arr[size_dq(info->a) - 1];
	info->a->arr[size_dq(info->a) - 1] = tem;
	info->total_count++;
}

//스택 b의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_b(t_info *info)
{
	write(1, "sb\n", 3);
	int tem = info->b->arr[info->b->top];
	info->b->arr[info->b->top] = info->b->arr[size_dq(info->b) - 1];
	info->b->arr[size_dq(info->b) - 1] = tem;
	info->total_count++;
}

//sa와 sb를 동시에 실행한다.
void	ss(t_info *info)
{
	write(1, "ss\n", 3);
	swap_a(info);
	swap_b(info);
	info->total_count++;
}
// 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 
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

//스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 
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

// 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
void	rotate_a(t_info *info)
{
	write(1, "ra\n", 3);
	if (!empty_dq(info->a))
	{
		push_bottom_dq(top_dq(info->a), info->a);
		top_pop_dq(info->a);
		info->total_count++;
	}
}

// 스택 b의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
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

//ra와 rb를 동시에 실행한다.
void	rr(t_info *info)
{
	write(1, "rr\n", 3);
	rotate_a(info);
	rotate_b(info);
	info->total_count++;
}

//스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
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

//스택 b의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
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

//rra와 rrb를 동시에 실행한다.
void	rrr(t_info *info)
{
	write(1, "rrr\n", 4);
	rev_rotate_a(info);
	rev_rotate_b(info);
	info->total_count++;
}

