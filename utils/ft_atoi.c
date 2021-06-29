/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:17:33 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/30 04:11:26 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		space_check(char b)
{
	if (b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\f'
		|| b == '\v')
		return (1);
	return (0);
}

int		ft_atoi(char *str, char *s, int *numarr)
{
	long	i;
	long	m;
	long	num;

	m = 1;
	i = 0;
	num = 0;
	while (space_check(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9' || str[i] == '\0')
		error_free("Error\n", str, s, numarr);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && m == 1) || (num > 2147483648 && m == -1))
			error_free("Error\n", str, s, numarr);
		i++;
	}
	if (str[i] != '\0')
		error_free("Error\n", str, s, numarr);
	return (num * m);
}
