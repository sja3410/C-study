#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<iterator>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
vector <int> v;
int main(void)
{
	int num1; long num2;
	int n;
	scanf("%d %ld", &num1, &num2);
	for (int i = 0; i < num1; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	int count = 0;
	int k = num1 - 1;
	while (num2 != 0)
	{
		if ((num2 / v[k]) == num2) {
			count += num2 / v[k];
			break;
		}
		count += num2 / v[k];
		num2 %= v[k--];
	}
	printf("%d\n", count);
	return 0;

}