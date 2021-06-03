#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque <int> a;
deque <int> b;
int cnt;

//스택 a의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_a()
{
	printf("sa\n");
	int tem = a.back();
	a.back() = 	a.at(a.back() - 1);
	a.at(a.back() - 1) = tem;
	cnt++;
}

//스택 b의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
void	swap_b()
{
	printf("sb\n");
	int tem = b.back();
	b.back() = 	b.at(b.back() - 1);
	b.at(b.back() - 1) = tem;
	cnt++;
}

//sa와 sb를 동시에 실행한다.
void	ss()
{
	printf("ss\n");
	swap_a();
	swap_b();
	cnt++;
}
// 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 
void	push_a()
{
	printf("pa\n");
	if (!b.empty())
	{
		a.push_back(b.back());
		b.pop_back();
		cnt++;
	}
}

//스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 
void	push_b()
{
	if (!a.empty())
	{
		printf("pb\n");
		b.push_back(a.back());
		a.pop_back();
		cnt++;
	}
}

// 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
void	rotate_a()
{
	if (!a.empty())
	{
		printf("ra\n");
		a.push_front(a.back());
		a.pop_back();
		cnt++;
	}
}

// 스택 b의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
void	rotate_b()
{
	if (!b.empty())
	{
		printf("rb\n");
		b.push_front(b.back());
		b.pop_back();
		cnt++;
	}
}

//ra와 rb를 동시에 실행한다.
void	rr()
{
	printf("rr\n");
	rotate_a();
	rotate_b();
	cnt++;
}

//스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
void	rev_rotate_a()
{
	if (!a.empty())
	{
		printf("rra\n");
		a.push_back(a.front());
		a.pop_front();
		cnt++;
	}
}

//스택 b의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
void	rev_rotate_b()
{
	if (!b.empty())
	{
		printf("rrb\n");
		b.push_back(b.front());
		a.pop_front();
		cnt++;
	}
}

//rra와 rrb를 동시에 실행한다.
void	rrr()
{
	printf("rrr\n");
	rev_rotate_a();
	rev_rotate_b();
	cnt++;
}

