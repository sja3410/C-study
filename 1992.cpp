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
int check(int x, int y, int num1) //모두 1이면 1을 반환, 모두 0이면 0을 반환 색종이가 아니면 -1을 반환
{
	if (num1 == 1)
		return arr[x][y];
	int c = arr[x][y];
	for (int i = x; i < x + num1; i++)
		for (int j = y; j < y + num1; j++) {
			if (c != arr[i][j])
				return -1;//하나라도 틀리면
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
		divide(x, y, num1 / 2);//2사분면
		divide(x, y + (num1) / 2, num1 / 2);//1사분면
		divide(x + (num1) / 2, y, num1 / 2);//3사분면
		divide(x + (num1) / 2, y + (num1 / 2), (num1 / 2)); //4사분면
		printf(")");
	}
}
int main() {
	
	int num = input();
	divide(0, 0, num);
	return 0;
}
