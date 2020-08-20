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
vector <int> graph [110];
int n, countx, county, m;
int visit[110];


void input(void)
{
	int x, y;
	cin >> n >> countx >> county >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

int bfs(int num)
{
	queue<int> q;
	visit[num] = 0;
	q.push(num);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < (int)graph[curr].size(); i++)
		{
			int next = graph[curr][i];
			if (next == county)
			{
				return visit[curr] + 1;
			}
			else if (visit[next] == -1)
			{
				visit[next] = visit[curr] + 1;
				q.push(next);

			}
		}
	}
	return -1;

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(visit, -1, sizeof(visit));
	input();
	cout << bfs(countx) << '\n';
	return 0;

}