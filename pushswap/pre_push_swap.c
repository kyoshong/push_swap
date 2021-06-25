/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/26 02:43:54 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
	ft_split_atoi(combine_argv, ' ');
	return (NULL);
}

int		*get_list(int argc, char **argv)
{
	int i;
	int j;
	int len;
	
	i = 1;
	len = 0;
	while (argc > i)
	{
		printf("%d", len);
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

int		avail_arr(int len)
{
	int i;

	i = 1;
	if (len == 1)
		return (0);
	while (i < len)
	{
		if (s_arr[i] < s_arr[i - 1])
			return (1);
	}
	return (0);
}

void	pre_push_swap(int argc, char **argv)
{
	int len;

	printf("1");
	get_list(argc, argv);
	len = get_len(s_arr);
	printf("2");
	if (s_arr != NULL || avail_arr(len))
	{
		init_a(len);
		printf("3");
		init_b(len);
		printf("4");
		quick_sort(0, len - 1);
		printf("6");
		push_swap(len);
	}
	free(s_arr);
}
