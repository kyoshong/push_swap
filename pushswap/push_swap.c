/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 00:27:50 by hyospark         ###   ########.fr       */
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
	return(ft_split_atoi(combine_argv, ' '));
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
void	push_swap(int argc, char **argv)
{
	int *arr;
	int len;

	arr = get_list(argc, argv);
	len = get_len(arr);
	quick_sort(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
		printf("arr[%d] : %d\n",i, arr[i]);
	free(arr);
}
