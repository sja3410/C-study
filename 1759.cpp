#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;
int num1, num2;
vector<char> arr;
string check;

void print_password(string check, int n2)
{
	if (check.length() == num1)
	{
		int jaum = 0, moum = 0;
		for (char c: check)
		{
			if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
				moum++;
			else jaum++;
		}
		if (moum >= 1 && jaum >= 2) {
			cout << check << "\n";
		}
		return;
	}
	if (n2 >= num2) return;
	print_password(check+arr[n2],n2+1);
	print_password(check,n2+1);

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> num1 >> num2; //num1은 암호의 길이, num2는 입력한 문자의 개수
	char c;
	for (int i = 0; i < num2; i++)
	{
		cin >> c;
		arr.push_back(c);// 값 넣기
	}
	sort(arr.begin(), arr.end());//정렬 
	print_password(check, 0);
	return 0;

}
