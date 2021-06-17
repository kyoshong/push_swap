/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:48:51 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 15:50:07 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef	struct	s_dq
{
	int	*arr;
	int	front;
	int	back;
}				t_dq;

t_dq	*a;
t_dq	*b;

int		*make_list(char **argv, int len, int argc);
int		*get_list(int argc, char **argv);
void	pre_push_swap(int argc, char **argv);
void	div_pivot(int end);

int		ft_strlen(char *str);
int		space_check(char b);
int		ft_atoi(char *str);
int		*ft_split_atoi(char *s, char c);

void	init_a(int *val, int size);
void	init_b(int size);

void	ft_isnumber(char **arg, int argc);
void	print_error_free(char *error, char *tem_str);
void	print_error(char *error);

void	quick_sort(int *arr, int l, int r);
int		partition(int *arr, int l, int r);

#endif
