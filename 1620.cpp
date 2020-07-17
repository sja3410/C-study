#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num2, num;
	string name;
	scanf("%d %d", &num, &num2);
	map<string, string> u1;
	vector<string> name1;

	for (int i = 1; i < num + 1; i++)
	{
		cin >> name;
		u1.insert({ name, to_string(i) });
		u1.insert({ to_string(i), name });
	}
	for (int j = 0; j < num2; j++)
	{
		cin >> name;
		name1.push_back(name);
	}
	for (int k = 0; k < num2; k++)
		cout << u1.find(name1[k])->second << '\n';

	return 0;
}