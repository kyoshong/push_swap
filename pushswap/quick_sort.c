/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 03:50:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_arr(t_info *info, int a, int b)
{
	int tem;

	tem = info->s_arr[a];
	info->s_arr[a] = info->s_arr[b];
	info->s_arr[b] = tem;
}

int		partition(t_info *info, int l, int r)
{
	int i;

	i = l;
	while (l < r)
	{
		if (info->s_arr[l] > info->s_arr[r])
		{
			swap_arr(info, l, i);
			i++;
		}
		l++;
	}
	swap_arr(info, r, i);
	return (i);
}

void	quick_sort(t_info *info, int l, int r)
{
	int i;

	if (l < r)
	{
		i = partition(info, l, r);
		quick_sort(info, l, i - 1);
		quick_sort(info, i + 1, r);
	}
}
