
#include "../headers/push_swap.h"

void free_all()
{
	
}

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
	// int val;
	// for (int i = 0; i < num; i++)
	// {
	// 	scanf("%d", &val);
	// 	a.push_back(val);
	// 	arr[i] = a[i];
	// }
	// sort(arr[0], arr[num - 1]);
	// div_pivot(num/3);
	// div_pivot(num/3 * 2);

	// while (!b.empty())
	// {
	// 	sort_a();
	// }
	// printf("%d", cnt);
	// return 0;
}
