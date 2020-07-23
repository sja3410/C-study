#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<pair<int, int>> p;
	int num, x, y;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		p.push_back({ x,y });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < num; i++)
	{
		cout << p[i].first <<' '<< p[i].second <<'\n';
	}
	return 0;
}
		
		
