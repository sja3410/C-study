//��Ʈ��ŷ - DFS //vector
//�ִܰŸ� - BFS //ť �̿�


#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iterator>
#include<queue>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

int n, m, v;
vector <int> graph[1001];
bool visit[1001];
int dist[1001];

void input(void)
{
	int num1, num2;
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	for (int j = 1; j<=n; j++)//����� ��
	{
		sort(graph[j].begin(), graph[j].end());
	}
}
void dfs(int num)
{
	visit[num] =true; //���� ����
	cout << num << ' ';

	for (int i = 0; i < (int)graph[num].size(); i++)
	{
		int next = graph[num][i];
		if (!visit[next]) // �Ȱ��ٿ�
		{
			dfs(next);
		}
	}
}

void bfs(int num)
{
	queue<int> q;
	dist[num] = 0;
	q.push(num);

	while(!q.empty())
	{
		int curr = q.front();
		cout << curr << ' ';
		q.pop();

		for (int i = 0; i < (int)graph[curr].size(); i++)
		{
			int next = graph[curr][i];
			if (dist[next] == -1)
			{
				dist[next] = dist[curr] + 1;
				q.push(next);

			}
		}
	}

}
int main(void)
{
	cin >> n >> m >> v;
	input();
	dfs(v);
	cout << '\n';
	memset(dist, -1, sizeof(dist));
	bfs(v);

}
