#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<iterator>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

vector <pair<int, int>> v;

void input(int n)
{
	int num1, num2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &num1, &num2);
		v.push_back({ num1, num2 });
	}
}
bool cmp(pair<int, int> a, pair<int, int>b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}
int main(void)
{
	int n, count = 1;
	scanf("%d", &n);
	input(n);
	sort(v.begin(), v.end(),cmp);
	int max = v[0].second;
	for(int i= 1; i<n; i++)
	{
		if (max <= v[i].first)
		{
			max = v[i].second;
			count++;
		}
	}
	printf("%d", count);
	return 0;
}