/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:48:51 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/15 14:27:55 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_dq
{
	int			*arr;
	int			top;
	int			bottom;
}				t_dq;

typedef	struct	s_info
{
	t_dq		*a;
	t_dq		*b;
	int			*s_arr;
	int			s_len;
	int			total_count;
	int			find_min_t;
	int			find_min_b;
}				t_info;

int				avail_arr(t_info *info);
void			free_all(t_info *info);
int				get_len(int *arr);
int				*make_list(char **argv, int len, int argc, t_info *info);
int				*get_list(int argc, char **argv, t_info *info);
void			pre_push_swap(int argc, char **argv);
void			init_a(int size, t_info *info);
void			init_b(int size, t_info *info);
int				empty_dq(t_dq *dq);
void			push_top_dq(int val, t_dq *dq);
void			push_bottom_dq(int val, t_dq *dq);
void			top_pop_dq(t_dq *dq);
void			bottom_pop_dq(t_dq *dq);
int				top_dq(t_dq *dq);
int				bottom_dq(t_dq *dq);
int				size_dq(t_dq *dq);
void			swap_arr(t_info *info, int a, int b);
void			quick_sort(t_info *info, int l, int r);
int				partition(t_info *info, int l, int r);
void			five_push_swap(t_info *info, int len);
void			simple_push_swap(t_info *info, int len);
void			four_push_swap(t_info *info);
int				check_next_val(t_info *info, int len);
int				check_fin(t_info *info, int len);
void			push_swap(t_info *info, int len);
void			large_sort_pivot(t_info *info, int len, int size);
void			sorting_val(t_info *info, int big, int small, int limit);
void			div_pivot(t_info *info, int len, int num);
void			div_pivot_c(t_info *info, int len, int num);
void			div_pivot_b(t_info *info, int num, int div);
void			div_pivot_a(t_info *info, int len, int num);
int				find_short_bottom(t_info *info, int limit, int big, int small);
int				find_short_top(t_info *info, int limit, int big, int small);
int				max_val(int min, int count, int n, int result);
int				find_short(t_info *info, int limit, int big, int small);
int				move_top(t_info *info, int val, int rotate, int next_val);
int				move_bottom(t_info *info, int val, int rotate, int next_val);
void			find_one_val(t_info *info, int val);
int				ft_strlen(char *str);
int				space_check(char b);
void			check_dupl(int *numarr, int i, char *s, char *tem_str);
int				ft_atoi(char *str, char *s, int *numarr);
int				*split2(char *s, char c, int word_num, int i);
int				*ft_split_atoi(char *s, char c, t_info *info);
void			error_free(char *error, char *tem_str, char *s, int *numarr);
void			print_error(char *error);
void			ft_isnumber(char **arg, int argc);
void			swap_a(t_info *info);
void			swap_b(t_info *info);
void			ss(t_info *info);
void			push_a(t_info *info);
void			push_b(t_info *info);
void			rotate_a(t_info *info);
void			rotate_b(t_info *info);
void			rr(t_info *info);
void			rev_rotate_a(t_info *info);
void			rev_rotate_b(t_info *info);
void			rrr(t_info *info);

#endif
