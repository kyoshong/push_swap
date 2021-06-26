/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/27 03:07:48 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*make_list(char **argv, int len, int argc)
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
	return (ft_split_atoi(combine_argv, ' '));
}

int		*get_list(int argc, char **argv)
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
	return (make_list(argv, len, argc));
}

int		get_len(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		avail_arr(int len, t_info *info)
{
	int i;

	i = 1;
	if (len == 1)
		return (0);
	while (i < len)
	{
		if (info->s_arr[i] < info->s_arr[i - 1])
			return (1);
		i++;
	}
	return (0);
}

void	pre_push_swap(int argc, char **argv)
{
	int len;
	t_info *info;
	
	if (!(info = (t_info *)malloc(sizeof(*info))))
		return ;
	info->s_arr = get_list(argc, argv);
	info->total_count = 0;
	len = get_len(info->s_arr);
	if (info->s_arr != NULL && avail_arr(len, info))
	{
		init_a(len - 1, info);
		init_b(len - 1, info);
		quick_sort(info, 0, len - 1);
		push_swap(info, len);
	}
	free(info->s_arr);
	free(info);
}
