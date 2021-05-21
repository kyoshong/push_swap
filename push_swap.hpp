#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque <int> a;
deque <int> b;
int cnt, mid;


void	swap_a()
{
	printf("sa\n");
	int tem = a.back();
	a.back() = 	a.at(a.back() - 1);
	a.at(a.back() - 1) = tem;
	cnt++;
}

void	swap_b()
{
	printf("sb\n");
	int tem = b.back();
	b.back() = 	b.at(b.back() - 1);
	b.at(b.back() - 1) = tem;
	cnt++;
}

void	ss()
{
	printf("ss\n");
	swap_a();
	swap_b();
	cnt++;
}

void	rotate_a()
{
	printf("ra\n");
	a.push_front(a.back());
	a.pop_back();
	cnt++;
}

void	rotate_b()
{
	printf("rb\n");
	b.push_front(b.back());
	b.pop_back();
	cnt++;
}

void	rr()
{
	printf("rr\n");
	rotate_a();
	rotate_b();
	cnt++;
}

void	rev_rotate_a()
{
	printf("rra\n");
	a.push_back(a.front());
	a.pop_front();
	cnt++;
}

void	rev_rotate_b()
{
	printf("rrb\n");
	a.push_back(a.front());
	a.pop_front();
	cnt++;
}

void	rrr()
{
	printf("rrr\n");
	rev_rotate_a();
	rev_rotate_b();
	cnt++;
}

void	push_a()
{
	printf("pa\n");
	a.push_back(b.back());
	b.pop_back();
	cnt++;
}

void	push_b()
{
	printf("pb\n");
	b.push_back(a.back());
	a.pop_back();
	cnt++;
}