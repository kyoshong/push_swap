/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:07:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/24 02:34:01 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//스택 a의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_a()
{
	wirte(1, "sa\n", 3);
	int tem = a->top;
	a->arr[a->top] = a->arr[size_dq(a) - 1];
	a->arr[size_dq(a) - 1] = tem;
	total_count++;
}

//스택 b의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_b()
{
	wirte(1, "sb\n", 3);
	int tem = b->top;
	b->arr[b->top] = b->arr[size_dq(b) - 1];
	b->arr[size_dq(b) - 1] = tem;
	total_count++;
}

//sa와 sb를 동시에 실행한다.
void	ss()
{
	wirte(1, "ss\n", 3);
	swap_a();
	swap_b();
	total_count++;
}
// 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 
void	push_a()
{
	wirte(1, "pa\n", 3);
	if (!empty_dq(b))
	{
		push_top_dq(top_dq(b), a);
		top_pop_dq(b);
		total_count++;
	}
}

//스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 
void	push_b()
{
	wirte(1, "pb\n", 3);
	if (!empty_dq(a))
	{
		push_top_dq(top_dq(a), b);
		top_pop_dq(a);
		total_count++;
	}
}

// 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
void	rotate_a()
{
	wirte(1, "ra\n", 3);
	if (!empty_dq(a))
	{
		push_bottom_dq(bottom_dq(a), a);
		top_pop_dq(a);
		total_count++;
	}
}

// 스택 b의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
void	rotate_b()
{
	wirte(1, "rb\n", 3);
	if (!empty_dq(b))
	{
		push_bottom_dq(bottom_dq(b), b);
		top_pop_dq(b);
		total_count++;
	}
}

//ra와 rb를 동시에 실행한다.
void	rr()
{
	wirte(1, "rr\n", 3);
	rotate_a();
	rotate_b();
	total_count++;
}

//스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
void	rev_rotate_a()
{
	wirte(1, "rra\n", 4);
	if (!empty_dq(a))
	{
		push_top_dq(bottom_dq(a), a);
		bottom_pop_dq(a);
		total_count++;
	}
}

//스택 b의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
void	rev_rotate_b()
{
	wirte(1, "rrb\n", 4);
	if (!empty_dq(a))
	{
		push_top_dq(bottom_dq(b), b);
		bottom_pop_dq(b);
		total_count++;
	}
}

//rra와 rrb를 동시에 실행한다.
void	rrr()
{
	wirte(1, "rrr\n", 4);
	rev_rotate_a();
	rev_rotate_b();
	total_count++;
}

