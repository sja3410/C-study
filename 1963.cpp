#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<iterator>

#pragma warning (disable:4996)
using namespace std;
int visit[10001];
int x, y;


int sosu(int num) //소수 판별
{

	int k = (int)sqrt(num);
	for (int i = 2; i <= k; i++)
	{
		if (num % i == 0)
			return -1;
	}
	return 1; //소수이다.
}

int bfs(int num1, int num2, queue <int> q)
{
	visit[num1] = 0;
	q.push(num1);

	while (!q.empty())
	{
		int curr = q.front();
		if (curr == num2)
			return visit[curr];
		q.pop();

		int a100 = curr % 1000;
		int a10 = curr % 100;
		int a1 = curr % 10;
		for (int k = curr + 1000; k < 10000; k = k + 1000)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}
		for (int k = curr - 1000; k > 1000; k = k - 1000)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}//천의 자리수
		for (int k = curr + 100; k < curr + 1000 - a100; k = k + 100)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}
		for (int k = curr - 100; k > curr - a100; k = k - 100)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}//백의 자리수 
		for (int k = curr + 10; k < curr + 100 - a10; k = k + 10)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}
		for (int k = curr - 10; k > curr - a10; k = k - 10)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}//십의 자리수 
		for (int k = curr + 1; k < curr + 10 - a1; k = k + 1)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}
		for (int k = curr - 1; k > curr - a1; k = k - 1)
		{
			if (sosu(k) == 1 && visit[k] == -1) {
				visit[k] = visit[curr] + 1;
				q.push(k);
			}
		}//백의 자리수 

	}
	return -1;

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		queue <int> q;
		memset(visit, -1, sizeof(visit));
		cin >> x >> y;
		int count = bfs(x, y, q);
		if (count == -1)
			cout << "Impossible" << '\n';
		else cout << count << '\n';
	}

	return 0;
}