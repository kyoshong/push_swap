int		find_short(int limit, int big, int small)
{
	int *min;
	int *min2;
	int top;
	int bottom;

	min = 0;
	top = refind_short_top(&min, limit, big, small);
	bottom = find_short_bottom(&min2, limit, big, small);
	if (min > min2)
		
}