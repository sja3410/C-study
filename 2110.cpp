#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int v[200001];
int n, r;
int coun;
int pre;
void input(int n)
{
	int d;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
}
void search(int start, int end)
{
	if (start > end) {
		printf("%d\n", pre);
		return;
	}
	int c = 0;
	int mid = (start + end) / 2;

	coun = v[0];
	for (int i = 1; i < n; i++)
	{
		if (coun + mid <= v[i]) {
			coun = v[i];
			c++;
		}
	}
	if (c >=(r-1)) {
		pre = mid;
		search(mid + 1, end);
	}
	else search(start, mid - 1);
}

int main(void)
{
	scanf("%d %d", &n, &r);
	input(n);
	sort(v, v+n);
	search(1, (v[0] + v[n - 1]) / (r - 1));
	return 0;
}