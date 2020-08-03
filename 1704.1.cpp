#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;

int r, c;
int arr[2][2] = { 0,1,2,3 };
void divide(int x, int y, int num1)
{
	//printf("%d %d\n", x, y);
	static int count = 0;
	if (x <= r && x + 1 >= r && y <= c && y + 1 >= c) {
		printf("%d", arr[r % 2][c % 2] + 4 * count);
		return;
	}
	//else {
	if (num1 == 2) { //칸 수가 하나이면
		//printf("%d\n", count);
		count++;
		return;
	}
	else {
		divide(x, y, num1 / 2);
		divide(x, y + (num1) / 2, num1 / 2);
		divide(x + (num1) / 2, y, num1 / 2);//1사분면
		divide(x + (num1) / 2, y + (num1 / 2), (num1 / 2)); //4사분면
	}
	//}
}
int main() {

	int n;
	scanf("%d %d %d", &n, &r, &c);
	divide(0, 0, (int)pow(2, n));

	return 0;
}
