/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:17:33 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/29 03:27:37 by hyospark         ###   ########.fr       */
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
	long	minus;
	long	num;

	minus = 1;
	i = 0;
	num = 0;
	while (space_check(str[i]) == 1 && str[i] != '\0')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9' || str[i] == '\0')
		error_free("Error\natoi숫자가 아닙니다요", str, s, numarr);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && minus == 1) || (num > 2147483648 && minus == -1))
			error_free("Error\n범위를 벗어났어요", str, s, numarr);
		i++;
	}
	if (str[i] != '\0')
		error_free("Error\n뒤에 이상한 문자가 붙어있다!", str, s, numarr);
	return (num * minus);
}
