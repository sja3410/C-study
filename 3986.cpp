#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	char pre;
	int num;
	scanf("%d", &num);
	getchar();
	int count=0;
	for (int i = 0; i < num; i++) {
		stack <char> st;
		char c;
		while ((c = getchar()) != '\n')
		{	//�ѱ��ھ� �޾Ƽ� ���ÿ� ����
			if (st.empty() == true)
			{
				st.push(c);
			}
			else
			{
				pre = st.top(); //���� ����� ���� ������
				if (pre == c)
					st.pop();
				else
					st.push(c);
			}
		}
		if (st.empty() == true) {
			printf("�¾ҽ��ϴ�.\n");
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}