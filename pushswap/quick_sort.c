/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/25 16:44:45 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		partition(int l, int r)
{
	int i;
	int tem;

	i = l;
	while (l < r)
	{
		if (s_arr[l] < s_arr[r])
		{
			tem = s_arr[l];
			s_arr[l] = s_arr[i];
			s_arr[i] = tem;
			i++;
		}
		l++;
	}
	tem = s_arr[r];
	s_arr[r] = s_arr[i];
	s_arr[i] = tem;
	return (i);
}

void	quick_sort(int l, int r)
{
	int i;

	if (l < r)
	{
		i = partition(l, r);
		quick_sort(l , i - 1);
		quick_sort(i + 1 , r);
	}
	else
		return ;
}
