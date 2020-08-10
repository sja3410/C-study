#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int arr[10002];
vector <int> v;
void input(int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}
}
void print(int n)
{
	for (int i = 1; i < 10001; i++)
	{
		for(int j = 1; j<=arr[i]; j++)
			printf("%d\n", i);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	input(n);
	print(n);
	return 0;
}