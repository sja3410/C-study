#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<iterator>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
vector <int> v;

void input(void)
{
	int n, k, num;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << v[k - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}