/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 16:29:45 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_pivot(t_info *info, int big, int small, int limit)
{
	while (find_short_bottom(info, limit, big, small))
	{
		if (bottom_dq(info->a) == info->s_arr[0])
			break ;
		rrr(info);
	}
	while (bottom_dq(info->a) != info->s_arr[0])
		rev_rotate_a(info);
}

void	sorting_val(t_info *info, int big, int small, int limit)
{
	int i;

	while (!empty_dq(info->b) && big <= small)
	{
		if (!(i = find_short(info, limit, big, small)))
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
	}
	rev_rotate_pivot(info, big, small, limit);
}

void	large_sort_pivot(t_info *info, int len)
{
	int div;
	int i;

	if (top_dq(info->a) < bottom_dq(info->a))
		swap_a(info);
	div = len / 8;
	sorting_val(info, 1, div - 1, div);
	sorting_val(info, div + 1, div * 2, (div * 2) + 1);
	i = 2;
	while (i < 8)
	{
		sorting_val(info, (div * (i - 1)) + 1, div * i, (div * i) + 1);
		i++;
	}
	sorting_val(info, (div * 7) + 1, len - 1, len);
	push_a(info);
}

void	middle_sort_pivot(t_info *info, int len)
{
	int div;
	int i;

	if (top_dq(info->a) < bottom_dq(info->a))
		swap_a(info);
	div = len / 5;
	sorting_val(info, 1, div - 1, div);
	sorting_val(info, div + 1, div * 2, (div * 2) + 1);
	i = 0;
	while (i < 5)
	{
		sorting_val(info, (div * (i - 1)) + 1, div * i, (div * i) + 1);
		i++;
	}
	sorting_val(info, (div * 4) + 1, len - 1, len);
	push_a(info);
}

void	push_swap(t_info *info, int len)
{
	if (len <= 5)
		simple_push_swap(info, len);
	else
	{
		if (200 < len)
		{
			div_pivot(info, len - 1, 8);
			large_sort_pivot(info, len - 1);
		}
		else
		{
			div_pivot(info, len - 1, 5);
			middle_sort_pivot(info, len - 1);
		}
	}
}
