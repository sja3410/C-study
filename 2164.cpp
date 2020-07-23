#include<iostream>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num;
	queue <int> q;
	cin >> num;
	int i;
	for (i = 1; i <= num; i++)
	{
		q.push(i); //50¸¸¹ø
	}
	int size = num;
	while (q.size()!=1)
	{
		q.pop();
		q.push(q.front());
		if(q.size()!=1)
			q.pop();
	}
	printf("%d\n", q.back());

	return 0;
}