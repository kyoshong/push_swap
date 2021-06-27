/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/28 00:10:19 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*make_list(char **argv, int len, int argc, t_info *info)
{
	char *combine_argv;
	int i;
	int j;
	int z;
	
	ft_isnumber(argv, argc);
	if (!(combine_argv = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 1;
	z = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			combine_argv[z++] = argv[i][j++];
		combine_argv[z++] = ' ';
		i++;
	}
	return (ft_split_atoi(combine_argv, ' ', info));
}

int		*get_list(int argc, char **argv, t_info *info)
{
	int i;
	int j;
	int len;
	
	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		len += j + 1;
		i++;
	}
	return (make_list(argv, len, argc, info));
}

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

void	pre_push_swap(int argc, char **argv)
{
	t_info *info;
	
	if (!(info = (t_info *)malloc(sizeof(*info))))
		return ;
	info->s_arr = get_list(argc, argv, info);
	info->total_count = 0;
	if (info->s_arr != NULL && avail_arr(info))
	{
		init_b(info->s_len - 1, info);
		init_a(info->s_len - 1, info);
		quick_sort(info, 0, info->s_len - 1);
		push_swap(info, info->s_len);
	}
	//printf("total_count : %d\n", info->total_count);
	free(info->s_arr);
	free(info);
}
