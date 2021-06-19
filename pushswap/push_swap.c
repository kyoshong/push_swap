/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/18 11:14:16 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	div_pivot(int end)
{
	int limit = a[end];
	while (b.size() <= end + 1)
	{
		if (a.back() >= limit && !b.empty())
			rotate_a();
		else
			push_b();
	}
	// int val;
	// for (int i = 0; i < num; i++)
	// {
	// 	scanf("%d", &val);
	// 	a.push_back(val);
	// 	arr[i] = a[i];
	// }
	// sort(arr[0], arr[num - 1]);
	// div_pivot(num/3);
	// div_pivot(num/3 * 2);

	// while (!b.empty())
	// {
	// 	sort_a();
	// }
	// printf("%d", cnt);
	// return 0;
}

void	push_swap(int *arr, int len)
{
	div_pivot();
	
}
