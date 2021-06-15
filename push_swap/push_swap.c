/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/15 19:08:23 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int		sort_a(int start, int end)
{

}

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
}
void		make_list(char **argv, int len, int argc)
{
	char *combine_argv;
	int i;
	int j;
	int z;

	ft_isnumber(argv);
	if (!(combine_argv = (char *)malloc(sizeof(char) * (len + 1))))
		return ;
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
}

void		get_list(int argc, char **argv)
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
	make_list(argv, len, argc);
}

void	push_swap(int argc, char **argv)
{
	int *arr;
	
	arr = get_list(argc, argv);
}


