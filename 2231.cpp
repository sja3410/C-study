#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

long sumnum(long num)
{
	long sum = num;
	while (num > 10)
	{
		sum += (num % 10); num /= 10;
	}
	sum += num;
	return sum;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	char num[7];
	long num1;
	scanf("%s", num);
	int len = strlen(num);
	int c = num[0]-'0';
	num1 = atoi(num);
	for (long i = num1 - c - (9 * (len - 1)); i <= num1; i++)
	{
		if (sumnum(i) == num1) {
			printf("%ld", i); return 0;
		}
	}
	printf("0");
	return 0;
	

}