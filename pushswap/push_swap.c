/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/21 23:39:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	div_pivot(int *arr, int len)
{
	int i;
	int p1;
	int p2;
	
	p1 = arr[len - len/3];
	p2 = arr[len - (len/3 * 2)];
	i = 0;
	while (i < len)
	{
		if (top_dq(a) > p1) 
			rotate_a();
		else if (top_dq(a) <= p1 && top_dq(a) > p2)
			push_b();
		else if (top_dq(a) <= p2)
		{
			push_b();
			if ()
		}
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
	count = 0;
	div_pivot(arr, len);
	
}
