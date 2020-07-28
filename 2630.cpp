#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int arr[130][130];
int blue = 0, white = 0;

int input()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	return num;
}
int check(int x, int y, int num1) //모두 1이면 1을 반환, 모두 0이면 0을 반환 색종이가 아니면 -1을 반환
{
	if (num1 == 1)
		return arr[x][y];
	int c = arr[x][y];
	for (int i = x; i <x+num1; i++)
		for (int j =y; j < y+num1; j++) {
			if (c != arr[i][j])
				return -1;//하나라도 틀리면
		}
	return c;
}

void divide(int x, int y, int num1)
{
	int c = check(x, y, num1);
	if (c == 0) {
		white++;
		return;
	}
	if (c == 1) {
		blue++;
		return;
	}

	else {
		divide(x, y, num1/2);//2사분면
		divide(x,y+(num1)/2, num1/2);//1사분면
		divide(x+(num1)/2, y, num1/2);//3사분면
		divide(x+(num1)/2, y+(num1/2),(num1/2)); //4사분면
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num = input();
	divide(0, 0, num);
	printf("%d\n%d", white, blue);

	return 0;
}
