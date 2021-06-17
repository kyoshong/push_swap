/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 15:27:01 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		partition(int *arr, int l, int r)
{
	int i;
	int tem;

	i = l;
	while (l < r)
	{
		if (arr[l] < arr[r])
		{
			tem = arr[l];
			arr[l] = arr[i];
			arr[i] = tem;
			i++;
		}
		l++;
	}
	tem = arr[r];
	arr[r] = arr[i];
	arr[i] = tem;
	return (i);
}

void	quick_sort(int *arr, int l, int r)
{
	int i;

	if (l < r)
	{
		i = partition(arr, l, r);
		quick_sort(arr, l , i - 1);
		quick_sort(arr, i + 1 , r);
	}
	else
		return ;
}
