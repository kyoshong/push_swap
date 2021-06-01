#include "push_swap.hpp"

void	div_pivot(int end)
{
	int limit = a[end];
	while (b.size() <= end + 1)
	{
		if (a.back() >= limit)
		{
			rotate_a();
		}

		else
			push_b();
	}
}

int main()
{
	int num;
	cin >> num;
	int arr[num];
	int val;
	for (int i = 0; i < num; i++)
	{
		cin >> val;
		a.push_back(val);
		arr[i] = a[i];
	}
	sort(arr[0], arr[num - 1]);
	div_pivot(num/3);
	div_pivot(num/3 * 2);

	while (1)
	{
		if (a.back() != )
			swap_a();
		else if (a.at(a.back() - 1) != arr[mid-1])
			rotate_a();
		else
			break ;
	}
	
	return 0;
}
