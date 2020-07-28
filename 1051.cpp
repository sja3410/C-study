#include<iostream>
#include<stdio.h>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, num, max;
	int arr[51][51];
	scanf("%d %d", &n, &m);
	if (n < m) max = n;
	else max = m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}
	int len, maxlen = 1;
	//Å½»ö
	for (len = 0; len <max; len++)
	{
		for (int i = 0; i < n - len; i++)
		{
			for (int j = 0; j < m - len; j++)
			{
				if (arr[i][j] == arr[i + len][j] && arr[i][j] == arr[i][j + len] && arr[i][j] == arr[i + len][j + len])
				{
					if (maxlen <= len)
						maxlen = len+1;
				}
			}
		}
	}
	printf("%d", maxlen * maxlen);
	return 0;
}