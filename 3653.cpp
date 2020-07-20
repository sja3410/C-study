#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num1, num2, total, i, j;
	int c;
	scanf("%d", &total);
	list<int>::iterator iter;
	for (i = 0; i < total; i++)
	{
		list<int> q;
		scanf("%d %d", &num1, &num2);
		for (int i = 1; i <= num1; i++)
			q.push_back(i);//리스트에 원소 삽입 1,2,3
		vector<int> arr;
		for (j = 0; j < num2; j++)
		{
			int count = 0;
			scanf("%d", &c); //처음에는 4
			iter = q.begin();
			while ((*iter) != c)
			{
				count++;
				iter++;
			}
			printf("%d ", count);
			q.erase(iter);
			q.push_front(c);
			arr.push_back(count);
		}
		printf("\n");
	}
	return 0;
}
