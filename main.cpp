#include "push_swap.hpp"

int	mid_sort(int num, int mid)
{
	int num;
	sort(a.begin(), a.end());
	mid = a[num/2];
	for (int i = 0; i < num; i++)
	{
		if (a.back() > mid)
			push_b();
		else
			rotate_a();
	}
	return mid;
}

int main(int argc, char const *argv[])
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
	//mid = mid_sort(num, mid);
	sort(arr.begin(), arr.end());
	mid = a[num/2];
	for (int i = 0; i < num; i++)
	{
		if (a.at(a.size() - 1) > mid)
			rotate_a();
	}
	while (1)
	{
		if (a.back() != mid)
			swap_a();
		else if (a.at(a.back() - 1) != arr[mid-1])
			rotate_a();
		else
			break ;
	}
	
	return 0;
}
