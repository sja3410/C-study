#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

bool check(int che)
{
	vector<int> q;
	int tmp, a;
	while (che > 0)
	{
		q.push_back(che % 10);
		che /= 10;
	}
	a = q[0] - q[1];
	for (int i = 1; i < q.size() - 1; i++)
	{
		if (q[i] - q[i + 1] != a)
			return false;
	}
	return true;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num; 
	int count = 0;
	cin >> num; //숫자를 입력받는다.
	for (int i = 1; i <= num; i++)
	{
		if (i < 10) count++;
		else { if (check(i) == true) count++; }
	}
	printf("%d", count);
}