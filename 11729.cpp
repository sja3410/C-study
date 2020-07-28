#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

int count_hanoi(int n, int from, int by, int to) {
    static int count = 0;
    if (n == 1)
    {
        count++;
    }
    else {
        count_hanoi(n - 1, from, to, by); 
        count++; 
        count_hanoi(n - 1, by, from, to);   
    }
    return count;
}
void print_hanoi(int n, int from, int by, int to) {

    if (n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else {
        print_hanoi(n - 1, from, to, by);
        printf("%d %d\n", from, to);
        print_hanoi(n - 1, by, from, to);
    }
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num; 
	cin >> num;
    printf("%d\n", count_hanoi(num, 1, 2, 3));
    print_hanoi(num, 1, 2, 3);
    return 0;
}