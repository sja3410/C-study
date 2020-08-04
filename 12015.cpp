#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iterator>
#pragma warning (disable:4996)
using namespace std;

vector<int>v;

int main(void)
{
	int len, count = 1;
	int num;
	scanf("%d", &len);//수열의 길이
	scanf("%d", &num);
	v.push_back(num);
	for (int i = 1; i < len; i++)
	{
		scanf("%d", &num);
		if (v.back()>= num)
		{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), num);//LIS문제 필요 알고리즘 
			*iter = num;
		}
		else
		{
			v.push_back(num);
			count++;
		}
	}
	printf("%d", count);
	return 0;

}