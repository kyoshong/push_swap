/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:49:30 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/03 23:21:06 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_dq	*new_dq(int *val)
{
	t_dq	*n_dq;
	if (!(n_dq = (t_dq *)malloc(sizeof(*n_dq))))
	return (NULL);
	
	return (n_dq);
}

t_dq	*init_dq(int size, int *val)
{
	t_dq	*dq;
	t_dq	*tem;
	int		i;

	i = 0;
	dq = NULL;
	while (i < size)
	{
		
	}
	return (dq);
}

t_dq	empty_dq()
{
	
}

t_dq	push_back_dq()
{
	
}

t_dq	pop_front_dq()
{

}

t_dq	back_dq()
{
	
}

t_dq	at_dq()
{
	
}