#include<iostream>
#include<vector>
#include<stdio.h>
#pragma warning (disable:4996)
using namespace std;

int arr[65][65];

int input()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			scanf("%1d", &arr[i][j]);
	return num;
}
int check(int x, int y, int num1) //��� 1�̸� 1�� ��ȯ, ��� 0�̸� 0�� ��ȯ �����̰� �ƴϸ� -1�� ��ȯ
{
	if (num1 == 1)
		return arr[x][y];
	int c = arr[x][y];
	for (int i = x; i < x + num1; i++)
		for (int j = y; j < y + num1; j++) {
			if (c != arr[i][j])
				return -1;//�ϳ��� Ʋ����
		}
	return c;
}

void divide(int x, int y, int num1)
{
	int c = check(x, y, num1);
	if (c == 0) {
		printf("0");
		return;
	}
	if (c == 1) {
		printf("1");
		return;
	}

	else {
		printf("(");
		divide(x, y, num1 / 2);//2��и�
		divide(x, y + (num1) / 2, num1 / 2);//1��и�
		divide(x + (num1) / 2, y, num1 / 2);//3��и�
		divide(x + (num1) / 2, y + (num1 / 2), (num1 / 2)); //4��и�
		printf(")");
	}
}
int main() {
	
	int num = input();
	divide(0, 0, num);
	return 0;
}
