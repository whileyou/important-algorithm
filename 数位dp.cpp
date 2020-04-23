#include <bits/stdc++.h>	//hdu2089
using namespace std;
int n,m,dp[10][10];		//dp前一个代表位数，后一个代表最高位的数字的值 
int ask(int n)
{
	int x[10],len=0,ans=0;
	while(n)
	{
		x[++len]=n%10;
		n=n/10;
	}
	x[len+1]=0;
	for(int i=len;i>=1;i--)
	{
		for(int j=0;j<x[i];j++)
		{
			if(j!=4&&(x[i+1]!=6||j!=2))
			ans+=dp[i][j];
		}
		if(x[i]==4||(x[i+1]==6&&x[i]==2)) break;
	}
	return ans;
}
int main()
{
	//初始化
	for(int j=0;j<10;j++) dp[1][j]=1;
	dp[1][4]=0;
	for(int i=2;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(j!=4&&k!=4&&!(j==6&&k==2))
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
	while(~scanf("%d %d",&n,&m)&&(n||m))
	{
		printf("%d\n",ask(m+1)-ask(n));	//前缀和思想得答案 
	}
	return 0;
}
