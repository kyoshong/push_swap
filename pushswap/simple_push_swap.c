/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:24:02 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 02:21:09 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

int		check_fin(t_info *info, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (info->a->arr[i] != info->s_arr[i])
			return (1);
		i++;
	}
	return (0);
}

int		check_next_val(t_info *info, int len)
{
	int i;
	int top;

	top = info->a->top;
	i = 0;
	while (i < len)
	{
		if (top_dq(info->a) == info->s_arr[i])
		{
			if (info->a->arr[top - 1] == info->s_arr[i + 1])
				return (1);
			break ;
		}
		i++;
	}
	return (0);
}

void	four_push_swap(t_info *info)
{
	while (1)
	{
		if (top_dq(info->a) == info->s_arr[3])
		{
			push_b(info);
			break ;
		}
		else
			rotate_a(info);
	}
	simple_push_swap(info, 3);
	push_a(info);
}

void	five_push_swap(t_info *info, int len)
{
	int i;

	i = 0;
	for (int i = 0; i < len; i++)
	{
		if (top_dq(info->a) < info->s_arr[len / 2])
			push_b(info);
		else
			rotate_a(info);
	}
	if (top_dq(info->b) < bottom_dq(info->b))
		swap_b(info);
	simple_push_swap(info, 3);
	while (!empty_dq(info->b))
		push_a(info);
}

void	simple_push_swap(t_info *info, int len)
{
	if (len == 2)
	{
		if (top_dq(info->a) > bottom_dq(info->a))
			swap_a(info);
	}
	else if (len == 3)
	{
		while (!(info->s_arr[0] == bottom_dq(info->a) && 
				info->s_arr[2] == top_dq(info->a)))
		{
			if (info->s_arr[0] == top_dq(info->a) && 
				info->s_arr[2] == bottom_dq(info->a))
				rotate_a(info);
			else if (top_dq(info->a) > bottom_dq(info->a))
				rev_rotate_a(info);
			else
				swap_a(info);
		}
	}
	else if (len == 5)
		five_push_swap(info, len);
	else
		four_push_swap(info);
}
