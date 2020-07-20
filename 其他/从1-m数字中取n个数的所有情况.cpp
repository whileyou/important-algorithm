#include <bits/stdc++.h>
using namespace std;
int n,m,ans[100000];
void solve(int m1,int n1)
{
	if(!n1)
	{
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		printf("\n");return;
	}
	for(int i=1;m1+i<=m;i++)
	{
		ans[n-n1]=m1+i;
		solve(m1+i,n1-1);
	}
}
int main()
{
	printf("从数字1-m中取n个数\n—————————\n输入:\nm= ");
	scanf("%d",&m);
	printf("n= ");
	scanf("%d",&n);
	printf("\nsolve......\n所有情况为:\n");
	solve(0,n);
	return 0;
}
