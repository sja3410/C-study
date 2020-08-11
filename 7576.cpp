#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<iterator>

#pragma warning (disable:4996)
using namespace std;
int m, n;

queue <pair<int, int>> q;
int map[1001][1001];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void input(void)
{
	cin >> m >> n;
	int tomato;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> tomato;
			map[i][j] = tomato;
			if (tomato == 1)
				q.push(make_pair(i, j));//1으로 쓰여져 있음 q에 넣음
		}
	}
}

void bfs(void)
{
	int next_fir, next_sec, curr_fir, curr_sec;
	while (!q.empty())
	{
		curr_fir = q.front().first;
		curr_sec = q.front().second;
		//cout << curr_fir << ' '<< curr_sec << '\n';
		//map[curr_fir][curr_sec] = 1;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			next_fir = curr_fir+dy[i];
			next_sec = curr_sec + dx[i];
			if ((next_fir < 0) || (next_fir >= n) || (next_sec < 0) || (next_sec >= m))
				continue;

			if (map[next_fir][next_sec] == 0)
			{
				map[next_fir][next_sec] = map[curr_fir][curr_sec] + 1;
				q.push(make_pair(next_fir, next_sec));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0) {
				cout << "-1\n";
				return;
			}
	}
	cout << map[curr_fir][curr_sec]-1 << '\n';

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	input();
	bfs();
	return 0;
}