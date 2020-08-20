#include<iostream>
#include<vector>
#include<queue>


using namespace std;
int n, m;
vector <int> graph[1001];
bool visit[1001]; // false로 초기화 
queue <int> q;


void input(void)
{
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

}

void dfs(int num)
{
	visit[num] = true;
	for (int i = 0; i < graph[num].size(); i++)
	{
		int next = graph[num][i];
		if (!visit[next])
			dfs(next);
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	input();
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{	
		if (!visit[i]) {
			dfs(i);
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}