#include <bits/stdc++.h>
using namespace std;
int main()    //��ŵ���ݹ�
{
    void hanoi(int n,char one,char two,char three);
	int m;
	printf("��������������");
	cin>>m;
	printf("�ƶ�%d�����ӵĲ����ǣ�\n",m);
	hanoi(m,'A','B','C');
	getchar();
	getchar();
	return 0;
}
void hanoi(int n,char one,char two,char three)
{
	void move(char x,char y);
	if(n==1)move(one,three);
	else
	{
		hanoi(n-1,one,three,two);
		move(one,three);
		hanoi(n-1,two,one,three);
	}
}
void move(char x,char y)
{
	printf("%c->%c\n",x,y);
}
