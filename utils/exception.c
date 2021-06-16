/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:35:36 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 01:01:25 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void		ft_isnumber(char **arg, int argc)
{
	int i;
	int j;

	j = 0;
	i = 1;


	while (i < argc)
	{
		while (arg[i][j])
		{
			if ((arg[i][j] < '0' && arg[i][j] > '9') && arg[i][j] != ' '
			&& arg[i][j] != '-' && arg[i][j] != '+')
				print_error("Error\n숫자가 아닙니다요");
			j++;
		}
		i++;
	}
}

void	print_error(char *error)
{
	write(1, error, ft_strlen(error));
	exit(0);
}

void	print_error_free(char *error, char *tem_str)
{
	write(1, error, ft_strlen(error));
	free(tem_str);
	exit(0);
}
