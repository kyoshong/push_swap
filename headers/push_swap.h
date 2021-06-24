/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:48:51 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/24 17:15:43 by hyospark         ###   ########.fr       */
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
	int	top;
	int	bottom;
}				t_dq;


t_dq	*a;
t_dq	*b;
int		*s_arr;
int		total_count;

//main
int		*make_list(char **argv, int len, int argc);

//pre_push_swap
int		*make_list(char **argv, int len, int argc);
int		*get_list(int argc, char **argv);
void	pre_push_swap(int argc, char **argv);
void	div_pivot(int len);

//handle
//quick_sort
void	quick_sort(int *arr, int l, int r);
int		partition(int *arr, int l, int r);

//push_swap
void	init_a(int *val, int size);
void	init_b(int size);
int		empty_dq(t_dq *dq);
void	push_bottom_dq(int val, t_dq *dq);
void	push_top_dq(int val, t_dq *dq);
int		size_dq(t_dq *dq);
int		at_dq(int val, t_dq *dq);
int		bottom_dq(t_dq *dq);
void	top_pop_dq(t_dq *dq);
void	bottom_pop_dq(t_dq *dq);
int		top_dq(t_dq *dq);

int		find_short(int limit, int val, int val2);
int		find_val_bottom(int val, int val2, int next_val);

void	ft_isnumber(char **arg, int argc);
void	print_error_free(char *error, char *tem_str);
void	print_error(char *error);

int		find_val_top(int val, int val2, int next_val);

//split_atoi
int		ft_strlen(char *str);
int		space_check(char b);
int		ft_atoi(char *str);
int		*ft_split_atoi(char *s, char c);


void	push_swap(int len);
int		find_one_val(int val);


// commands
void	swap_a();
void	swap_b();
void	ss();
void	push_a();
void	push_b();
void	rotate_a();
void	rotate_b();
void	rr();
void	rev_rotate_a();
void	rev_rotate_b();
void	rrr();

#endif