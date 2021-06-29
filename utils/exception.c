/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:35:36 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 04:07:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_isnumber(char **arg, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (arg[i][j])
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9') && arg[i][j] != ' ' \
			&& arg[i][j] != '-' && arg[i][j] != '+')
				print_error("Error\n");
			j++;
		}
		i++;
	}
}

void	print_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(0);
}

void	error_free(char *error, char *tem_str, char *s, int *numarr)
{
	write(2, error, ft_strlen(error));
	free(s);
	free(numarr);
	free(tem_str);
	exit(0);
}
