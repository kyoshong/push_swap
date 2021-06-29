/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 03:41:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 03:42:10 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	div_pivot_a(t_info *info, int len, int num)
{
	int i;
	int p1;
	int p2;

	p1 = info->s_arr[0];
	p2 = info->s_arr[len / num];
	i = 0;
	while (i <= len / num)
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

void	div_pivot_b(t_info *info, int num, int div)
{
	int i;
	int p1;
	int p2;

	p1 = info->s_arr[num];
	p2 = info->s_arr[div];
	i = 0;
	while (i < div + 1)
	{
		if (top_dq(info->a) >= p1)
			rotate_a(info);
		else
		{
			push_b(info);
			if (top_dq(info->a) >= p1 && top_dq(info->b) < (p1 + p2) / 2)
				rr(info);
			else if (top_dq(info->b) < (p1 + p2) / 2)
				rotate_b(info);
		}
		i++;
	}
}

void	div_pivot_c(t_info *info, int len, int num)
{
	int i;
	int p1;
	int div;

	div = len / num;
	p1 = info->s_arr[div * (num - 1)];
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
}

void	div_pivot(t_info *info, int len, int num)
{
	int div;
	int	j;

	div = len / num;
	div_pivot_c(info, len, num);
	j = num - 2;
	while (j > 0)
	{
		div_pivot_b(info, div * j, div * (j + 1));
		j--;
	}
	div_pivot_a(info, len, num);
}
