#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<iterator>

#pragma warning (disable:4996)
using namespace std;
vector <int> graph[27];
int map[27][27];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n;
int v[627] = { 0 };
int num;

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf("%1d", &map[i][j]);
}

int dfs(int x, int y, int i)
{	
	num++;
	map[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];
		if ((cx < 0) || (cx >= n) || (cy < 0) || (cy >= n))
			continue;
		if (map[cx][cy] == 1) {
			dfs(cx, cy, num);
		}
	}
	return num;
}

int main(void)
{
	int count = 0, k= 0;
	input();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1) {
				count++;
				v[k++] = dfs(i, j, 0);
				num = 0;
			}
		}
	}
	sort(v, v+count);
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		printf("%d\n", v[i]);
	return 0;
}