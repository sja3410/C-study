#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

char arr[1002][52];
int r, c;

void search(void)
{
	static int count = 0;
	for (int i = 0; i < c; i++)
	{
		int ham[4] = { 0, 0, 0, 0 };
		for (int j = 0; j < r; j++)
		{
			if (arr[j][i] == 'A') ham[0]++;
			else if (arr[j][i] == 'C') ham[1]++;
			else if (arr[j][i] == 'G') ham[2]++;
			else if (arr[j][i] == 'T') ham[3]++;
		}
		int s = 0;
		int max = ham[0];
		for (int k = 1; k < 4; k++) {
			if (max >= ham[k])
				count += ham[k];
			else {
				count += max;
				max = ham[k];
				s = k;
			}
		}
		if (s == 0) cout << "A";
		else if (s == 1) cout << "C";
		else if (s == 2) cout << "G";
		else cout << "T";
	}
	cout << '\n'<<count;
	
}
void input(void)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> r >> c;
	input();
	search();
}