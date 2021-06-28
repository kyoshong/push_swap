/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:12:02 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/29 03:07:14 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		move_top(t_info *info, int val, int rotate, int next_val)
{
	int tem;
	
	if (next_val && rotate)
		tem = val - 1;
	else if (next_val)
		tem = val + 1;
	else
		tem = val;
	// if (info->s_arr[tem] == 34 || info->s_arr[tem] == 35)
	// {
	// 	printf("\n-------------start-----------\n");
	// 	printf("rotate : %d next_val : %d\n",  rotate, next_val);
	// 	printf("tem : %d  val : %d\n", tem, val);
	// }
	while (1)
	{
		if (top_dq(info->b) == info->s_arr[tem])
			break ;
		rotate_b(info);
	}
	push_a(info);
	if (next_val)
	{
		find_one_val(info, val);
		// if (top_dq(info->a) > info->a->arr[info->a->top - 1])
		// 	swap_a(info);
		if (rotate)
			rotate_a(info);
		else
			swap_a(info);
	}
	if (rotate)
		rotate_a(info);
	// if (info->s_arr[tem] == 34 || info->s_arr[tem] == 35)
	// {
	// 	printf("\n-------------end-----------\n");
	// 		for (int i = 100; i >= 0; i--)
	// 	{
	// 		printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
	// 	}
	// 		printf("------------------\na  b\n");
	// }
	return (2);
}

int		move_bottom(t_info *info, int val, int rotate, int next_val)
{
	int tem;
	
	if (next_val && rotate)
		tem = val - 1;
	else if (next_val)
		tem = val + 1;
	else
		tem = val;
	// 	if (info->s_arr[tem] == 34 || info->s_arr[tem] == 35)
	// {
	// 	printf("\n-------------start-----------\n");
	// 	printf("rotate : %d next_val : %d\n",  rotate, next_val);
	// 	printf("tem : %d  val : %d\n", tem, val);
	// }
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
	// 		if (info->s_arr[tem] == 34 || info->s_arr[tem] == 35)
	// {
	// 	printf("\n-------------end-----------\n");
	// 		for (int i = 100; i >= 0; i--)
	// 	{
	// 		printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
	// 	}
	// 		printf("------------------\na  b\n");
	// }
		if (rotate)
			rotate_a(info);
		else
			swap_a(info);
	}
	if (rotate)
		rotate_a(info);

	return (2);
}

void	find_one_val(t_info *info, int val)
{
	int i;
	int j;

	i = info->b->top;
	j = info->b->bottom;
	while (i >= j)
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
