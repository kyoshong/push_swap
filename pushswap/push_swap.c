/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/29 03:35:48 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	div_pivot_a(t_info *info, int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = info->s_arr[0];
	p2 = info->s_arr[len / 3];
	i = 0;
	while (i <= len / 3)
	{
		if (top_dq(info->a) == p1 || top_dq(info->a) == p2)
			rotate_a(info);
		else
		{
			push_b(info);
			if (top_dq(info->b) < p2 + ((p1 - p2) / 2))
				rotate_b(info);
		}
		i++;
	}
}

void	div_pivot_b(t_info *info, int len)
{
	int i;
	int p1;
	
	p1 = info->s_arr[len];
	i = 0;
	while (i < len * 2 + 1)
	{
		if (top_dq(info->a) >= p1)
			rotate_a(info);
		else
		{
			push_b(info);
			if (top_dq(info->a) >= p1 && top_dq(info->b) <= (p1 / 2))
				rr(info);
			else if (top_dq(info->b) <= (p1 / 2))
				rotate_b(info);
		}
		i++;
	}
}

void	div_pivot(t_info *info, int len)
{
	int i;
	int p1;

	p1 = info->s_arr[(len / 3) * 2];
	i = 0;
	while (i <= len)
	{
		if (top_dq(info->a) >= p1)
			rotate_a(info);
		else
		{
			push_b(info);
			if (top_dq(info->a) >= p1 && top_dq(info->b) > (p1 / 2))
				rr(info);
			else if (size_dq(info->b) > 1 && top_dq(info->b) > (p1 / 2))
				rotate_b(info);
		}
		i++;
	}
	div_pivot_b(info, len / 3);
	div_pivot_a(info, len);
}

void	sort_pivot2(t_info *info, int big, int small, int limit)
{
	int i;

	i = 0;
	while (!empty_dq(info->b) && big <= small)
	{
		if(!(i = find_short(info, limit, big, small)))
			break ;
		if (i == 1)
			move_top(info, big++, 0, 0);
		else if (i == 2)
			big += move_top(info, big, 0, 1);
		else if (i == 3)
			move_top(info, small--, 1, 0);
		else if (i == 4)
			small -= move_top(info, small, 1, 1);
		else if (i == 5)
			move_bottom(info, small--, 1, 0);
		else if (i == 6)
			small -= move_bottom(info, small, 1, 1);
		else if (i == 7)
			move_bottom(info, big++, 0, 0);
		else if (i == 8)
			big += move_bottom(info, big, 0, 1);
		// if (info->s_arr[small] == 37 || info->s_arr[small] == 38)
		// {
		// for (int i = 100; i >= 0; i--)
		// {
		// 	printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
		// }
		// 	printf("------------------\na  b\n");
		// }
	}
	while (bottom_dq(info->a) != info->s_arr[0])
		rev_rotate_a(info);
}

void	sort_pivot(t_info *info, int len)
{
	int div;
	
	if (top_dq(info->a) < bottom_dq(info->a))
		swap_a(info);
	div = len / 3;
	sort_pivot2(info, 1, div - 1, div);
	sort_pivot2(info, div + 1, div * 2, (div * 2) + 1);
	sort_pivot2(info, (div * 2) + 1, len - 1, len);
	push_a(info);
}

void	push_swap(t_info *info, int len)
{
	if (len <= 5)
		simple_push_swap(info, len);
	else
	{
		div_pivot(info, len - 1);
		sort_pivot(info, len - 1);
		// for (int i =info->s_len; i >= 0; i--)
		// printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
		// printf("------------------\n");
		// printf("a  b\n\n");
		// printf("total_count :%d\n", info->total_count);
	}
}
