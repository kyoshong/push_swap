/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 03:09:58 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		avail_arr(t_info *info)
{
	int i;

	i = 1;
	if (info->s_len == 1)
		return (0);
	while (i < info->s_len)
	{
		if (info->s_arr[i] < info->s_arr[i - 1])
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_info *info)
{
	free(info->s_arr);
	free(info->a->arr);
	free(info->a);
	free(info->b->arr);
	free(info->b);
	free(info);
}

void	pre_push_swap(int argc, char **argv)
{
	t_info *info;
	
	if (!(info = (t_info *)malloc(sizeof(*info))))
		return ;
	info->s_arr = get_list(argc, argv, info);
	info->total_count = 0;
	if (info->s_arr != NULL && avail_arr(info))
	{
		init_a(info->s_len, info);
		init_b(info->s_len, info);
		quick_sort(info, 0, info->s_len - 1);
		push_swap(info, info->s_len);
	}
	free_all(info);
}
