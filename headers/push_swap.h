/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:48:51 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/26 02:44:53 by hyospark         ###   ########.fr       */
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
int		get_len(int *arr);
int		*make_list(char **argv, int len, int argc);
int		*get_list(int argc, char **argv);
void	pre_push_swap(int argc, char **argv);
void	div_pivot(int len);

//handle_deque
void	init_a(int size);
void	init_b(int size);
int		empty_dq(t_dq *dq);
void	push_top_dq(int val, t_dq *dq);
void	push_bottom_dq(int val, t_dq *dq);

//handle_deque2
void	top_pop_dq(t_dq *dq);
void	bottom_pop_dq(t_dq *dq);
int		top_dq(t_dq *dq);
int		bottom_dq(t_dq *dq);
int		at_dq(int val, t_dq *dq);
int		size_dq(t_dq *dq);

//quick_sort
void	quick_sort(int l, int r);
int		partition(int l, int r);

//push_swap
void	push_swap(int len);
void	sort_pivot(int len);
void	sort_pivot2(int big, int small);
void	div_pivot(int len);
void	div_pivot_a(int len);
void	div_pivot_b(int len);

//push_swap2
int		find_short_bottom(int *min, int limit, int big, int small);
int		find_short_top(int *min, int limit, int big, int small);
int		max_val(int min, int count, int n, int result);
int		find_short(int limit, int big, int small);

//push_swap3
void	move_top(int val, int rotate, int next_val);
void	move_bottom(int val, int rotate, int next_val);
void	find_one_val(int val);

//split_atoi
int		ft_strlen(char *str);
int		space_check(char b);
void	check_dupl(int *numarr, int i, char *s, char *tem_str);
int		ft_atoi(char *str, char *s, int *numarr);
int		*split2(char *s, char c, int word_num, int i);
int		*ft_split_atoi(char *s, char c);

//exception
void	error_free(char *error, char *tem_str, char *s, int *numarr);
void	print_error(char *error);
void	ft_isnumber(char **arg, int argc);

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