#include <bits/stdc++.h>
using namespace std;
int main()    //汉诺塔递归
{
    void hanoi(int n,char one,char two,char three);
	int m;
	printf("请输入盘子数：");
	cin>>m;
	printf("移动%d个盘子的步骤是：\n",m);
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
