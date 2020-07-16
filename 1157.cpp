#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int set = 0;
	int arr[26] = { 0 };
	char c;
	while ((c = getchar()) != '\n') {
		if (c >= 97) arr[c - 97]++;
		else if(c>=65) arr[c - 65]++;
	}
	
	int max = 0;
	for (int i = 1; i < 26; i++)
	{
		if (arr[i] == 0)
			continue;
		if (arr[max] == arr[i]) set = 1;
		else if (arr[max] < arr[i]) { set = 0; max = i; }
	}
	if (set == 1) printf("?\n");
	else printf("%c\n", max + 65);
	return 0;
}