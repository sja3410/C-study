#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int v, e;
int parent[10002]; //�θ� ������ ����Ʈ
int rank[10002]; //��ũ�� �� 0���� �ʱ�ȭ
typedef struct edge {
	int v1, v2, w;
}edge;

vector<edge> vlist;

bool compare(edge a, edge b) //����ġ�� �������� ����
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
	sort(vlist.begin(), vlist.end(), compare); // ����ġ�� �������� ����
}

int find(int v)
{
	if (parent[v] == v) //���� �θ� ������ �׳� �״�� �� ����
		return v;
	else
		return find(parent[v]); // �ƴϸ� �θ�� findȣ��
}

void union_(int v1, int v2) { //union find��� ����
	int x, y;
	x = find(v1); 
	y = find(v2);
	if (x < y) //�� ���� ���� �θ� �ȴ�. +��ũ ��꿡���� ��ũ���� +1������
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
		parent[i] = i; //�θ� �迭 �ʱ�ȭ 
	}
	input();

	for (int i = 0; i < vlist.size(); i++) //�ϴ��� ��� ������ �� ����
	{
		if (find(vlist[i].v1) != find(vlist[i].v2)) // �θ� ������ ����Ŭ �߻� --> �������� ���� ����ġ�� ���� �������� �Ѿ
		{
			union_(vlist[i].v1, vlist[i].v2);
			answer += vlist[i].w; //���� ����
		}
	}
	cout << answer << '\n';

	return 0; 
}