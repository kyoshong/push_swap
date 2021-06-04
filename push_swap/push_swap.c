/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:01 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/04 17:12:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


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

int	*get_list(int argc, char **argv)
{
	int i;
	
	i = 1;
	while (argc > i)
	{
		ft_split()
		ft_atoi(argv[i]);
		i++;
	}
	retrun ();
}

int main(int argc, char const *argv[])
{
	
	if (argc < 2)
		write(1, "Error\n", 6);
	else
	{
		get_list(argc, argv);
	}
	return (0);
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
