#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	char pre;
	int num;
	scanf("%d", &num);
	getchar();
	vector <bool> vc;
	int count = 0;
	for (int i = 0; i < num; i++) {
		stack <char> st;
		char c;
		while ((c = getchar()) != '\n')
		{	//한글자씩 받아서 스택에 저장
			if (st.empty() == true)
				st.push(c);
		//	else if (st.empty() == true && c == ')')
			//	continue;
			else if (c == '(')
				st.push(c);
			else if (c == ')')
			{
				pre = st.top(); //제일 상단의 것을 가져옴
				if (pre == '(')
					st.pop();
				else
					st.push(c);
			}
		}
		if (st.empty() == true)
			vc.push_back(true);
		else vc.push_back(false);
	}
	for (int i = 0; i < num; i++) {
		if (vc[i] == true)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}