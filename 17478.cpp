#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

void recursive(int num1, int num2)
{
	if (num2 == 0) {
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < num1; i++)
		{
			printf("____");
		}
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("��� �亯�Ͽ���.\n");
		return;
	}
	else {
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		recursive(num1, num2 - 1);
		for (int i = 0; i < num1 - num2; i++)
		{
			printf("____");
		}
		printf("��� �亯�Ͽ���.\n");
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num; 
	cin >> num;
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	recursive(num, num);
	return 0;
}