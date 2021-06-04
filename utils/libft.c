/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:17:33 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/03 18:18:53 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		space_check(char b)
{
	if (b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\f')
		return (1);
	else if (b == '\v')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	long	i;
	long	minus;
	long	num;

	minus = 1;
	i = 0;
	num = 0;
	while (space_check(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == '-')
		minus = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0' && (str[i] <= '9') && str[i] != '\0'))
	{
		num = (num * 10) + ((str[i] - '0'));
		if (num > 2147483647 && minus == 1)
			return (-1);
		if (num > 2147483648 && minus == -1)
			return (0);
		i++;
	}
	return (num * minus);
}
