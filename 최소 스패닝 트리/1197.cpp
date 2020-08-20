#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int v, e;
int parent[10002]; //부모를 저장할 리스트
int rank[10002]; //랭크는 다 0으로 초기화
typedef struct edge {
	int v1, v2, w;
}edge;

vector<edge> vlist;

bool compare(edge a, edge b) //가중치를 기준으로 정렬
{
	if (a.w > b.w)
		return false;
	if (a.w == b.w) {
		if (a.v1 > b.v1)
			return false;
	}
	else return true;
}
void input(void)
{
	int v1, v2, w;
	edge edg;
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> w;
		edg.v1 = v1; edg.v2 = v2; edg.w = w;
		vlist.push_back(edg);
	}
	sort(vlist.begin(), vlist.end(), compare); // 가중치를 기준으로 정렬
}

int find(int v)
{
	if (parent[v] == v) //값과 부모가 같으면 그냥 그대로 값 리턴
		return v;
	else
		return find(parent[v]); // 아니면 부모로 find호출
}

void union_(int v1, int v2) { //union find계산 순서
	int x, y;
	x = find(v1); 
	y = find(v2);
	if (x < y) //더 작은 값이 부모가 된다. +랭크 계산에서는 랭크에다 +1씩해줌
		parent[y] = x; 
	else
		parent[x] = y;
}


int main(void)
{
	cin >> v >> e;
	int answer = 0;
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i; //부모 배열 초기화 
	}
	input();

	for (int i = 0; i < vlist.size(); i++) //일단은 모든 간선을 다 돈다
	{
		if (find(vlist[i].v1) != find(vlist[i].v2)) // 부모가 같으면 사이클 발생 --> 다음으로 작은 가중치를 가진 간선으로 넘어감
		{
			union_(vlist[i].v1, vlist[i].v2);
			answer += vlist[i].w; //길이 증가
		}
	}
	cout << answer << '\n';

	return 0; 
}