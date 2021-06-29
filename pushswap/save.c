


// void	div_pivot_a(t_info *info, int len)
// {
// 	int i;
// 	int p1;
// 	int p2;
// 	p1 = info->s_arr[0];
// 	p2 = info->s_arr[len / 5];
// 	i = 0;
// 	while (i <= len / 5)
// 	{
// 		if (top_dq(info->a) == p1 || top_dq(info->a) == p2)
// 			rotate_a(info);
// 		else
// 		{
// 			push_b(info);
// 			if (top_dq(info->b) < p2 + ((p1 - p2) / 2))
// 				rotate_b(info);
// 		}
// 		i++;
// 	}
// }

// void	div_pivot_b(t_info *info, int len, int t_len)
// {
// 	int i;
// 	int p1;
// 	int p2;
	
// 	p1 = info->s_arr[len];
// 	p2 = info->s_arr[t_len];
// 	i = 0;
// 	while (i < t_len + 1)
// 	{
// 		if (top_dq(info->a) >= p1)
// 			rotate_a(info);
// 		else
// 		{
// 			push_b(info);
// 			if (top_dq(info->a) >= p1 && top_dq(info->b) < (p1 + p2) / 2)
// 				rr(info);
// 			else if (top_dq(info->b) < (p1 + p2) / 2)
// 				rotate_b(info);
// 		}
// 		i++;
// 	}
// }

// void	div_pivot_c(t_info *info, int len)
// {
// 	int i;
// 	int p1;
// 	int div;

// 	div = len / 5;
// 	p1 = info->s_arr[div * 4];
// 	i = 0;
// 	while (i <= len)
// 	{
// 		if (top_dq(info->a) >= p1)
// 			rotate_a(info);
// 		else
// 		{
// 			push_b(info);
// 			if (top_dq(info->a) >= p1 && top_dq(info->b) > (p1 / 2))
// 				rr(info);
// 			else if (size_dq(info->b) > 1 && top_dq(info->b) > (p1 / 2))
// 				rotate_b(info);
// 		}
// 		i++;
// 	}
// }


// void	div_pivot(t_info *info, int len, int num)
// {
// 	int div;
// 	div = len / num;

// 	div_pivot_b(info, div * 3, div * 4);
// 	div_pivot_b(info, div * 2, div * 3);
// 	div_pivot_b(info, div, div * 2);
// 	div_pivot_a(info, len);
// }

