/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:48:51 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/15 19:17:54 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int cnt;

typedef	struct	s_dq
{
	int	*arr;
	int	front;
	int	back;
}				t_dq;

int		ft_strlen(char *str);
int		space_check(char b);
int		ft_atoi(char *str);
int		*ft_split_atoi(char const *s, char c);
t_dq	*new_dq(int *val);
t_dq	*init_dq(int size, int *val);
void	ft_isnumber(char **arg);
void	print_error(char *error);

#endif
