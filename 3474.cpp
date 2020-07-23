#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

long count(long num)
{
	vector<long> v;
	int mul=5, count = 0;
	while (num / mul != 0)
	{
		count += (num / mul);
		mul *= 5;
	}
	return count;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num;
	long num1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> num1;
		printf("%ld\n", count(num1));
	}
	return 0;
}