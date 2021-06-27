/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 02:52:24 by hyospark         ###   ########.fr       */
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
	printf ("\n\np1 : %d  p2 : %d\n\n", p1, p2);
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
	printf("----------\n");
	for (int i = 9; i >= 0; i--)
		printf("%d %d\n", info->a->arr[i], info->b->arr[i]);
	printf("----------\na b \n\n");
	printf("b.top : %d // a.top : %d\n",info->b->top, info->a->top);
	}
}

void	div_pivot_b(t_info *info, int len)
{
	int i;
	int p1;
	
	p1 = info->s_arr[len];
	i = 0;
	printf ("\n\np1 : %d \n\n", p1);
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
		printf("----------\n");
		for (int i = 9; i >= 0; i--)
		printf("%d %d\n", info->a->arr[i], info->b->arr[i]);
		printf("----------\na b \n\n");
		printf("b.top : %d // a.top : %d\n",info->b->top, info->a->top);
	}
}

void	div_pivot(t_info *info, int len)
{
	int i;
	int p1;

	p1 = info->s_arr[(len / 3) * 2];
	i = 0;
	printf ("\n\np1 : %d \n\n", p1);
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
		printf("----------\n");
		for (int i = 9; i >= 0; i--)
		printf("%d %d\n", info->a->arr[i], info->b->arr[i]);
		printf("----------\na b \n\n");
		printf("b.top : %d // a.top : %d\n",info->b->top, info->a->top);
	}
	printf("-----------------------------\n");
		printf("-----------------------------\n");
	div_pivot_b(info, len / 3);
	printf("-----------------------------\n");
		printf("-----------------------------\n");
	div_pivot_a(info, len);
		printf("-----------------------------\n");
			printf("-----------------------------\n");
	printf("end div \n");
}

void	sort_pivot2(t_info *info, int big, int small)
{
	int i;
	int limit;

	i = 0;
	limit = small;
	while (big >= small)
	{
		i = find_short(info, limit, big, small);
		if (i == 1)
			move_top(info, big, 0, 0);
		else if (i == 2)
			move_top(info, big--, 0, 1);
		else if (i == 3)
			move_top(info, small, 1, 0);
		else if (i == 4)
			move_top(info, small++, 1, 1);
		else if (i == 5)
			move_bottom(info, small, 1, 0);
		else if (i == 6)
			move_bottom(info, small++, 1, 1);
		else if (i == 7)
			move_bottom(info, big, 0, 0);
		else if (i == 8)
			move_bottom(info, big--, 0, 1);
		big--;
		small++;
	}
}

void	sort_pivot(t_info *info, int len)
{
	int top;
	int bottom;
	int div;
	int i;
	if (top_dq(info->a) < bottom_dq(info->a))
		swap_a(info);
	div = len / 3;
	bottom = 0;
	i = 2;
	while (i >= 0)
	{
		top = bottom + 1;
		bottom = div * i;
		sort_pivot2(info, top, bottom +1);
		i--;
	}
}

void	push_swap(t_info *info, int len)
{
	// printf("\nbefore : \n");
	for (int i = 9; i >= 0; i--)
		printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
	printf("------------\n");
	printf("a  b\n\n");
	if (len <= 5)
		simple_push_swap(info, len);
	else
	{
		div_pivot(info, len - 1);
		sort_pivot(info, len - 1);
	}
	printf("\nafter : \n");
	for (int i = 9; i >= 0; i--)
		printf("%d  %d\n", info->a->arr[i], info->b->arr[i]);
	printf("------------\n");
	printf("a  b\n\n");

}
