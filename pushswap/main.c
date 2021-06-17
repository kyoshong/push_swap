/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/06/17 15:27:07 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/push_swap.h"

int main(int argc, char *argv[])
{
	
	if (argc < 2)
		write(1, "Error\n", 6);
	else
	{
		push_swap(argc, argv);
		//free_all();
	}
	system("leaks push_swap > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
