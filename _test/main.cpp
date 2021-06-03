#include "push_swap.hpp"

int		sort_a(int start, int end)
{

}

void	div_pivot(int end)
{
	int limit = a[end];
	while (b.size() <= end + 1)
	{
		if (a.back() >= limit && !b.empty())
			rotate_a();
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

	while (!b.empty())
	{
		sort_a();
	}
	printf("%d", cnt);
	return 0;
}
