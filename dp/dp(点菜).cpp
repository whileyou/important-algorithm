#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],dp[101][1001];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)  //品种 
	{
		for(int j=1;j<=m;j++)  //钱数 
		{
			if(a[i]==j) dp[i][j]=dp[i-1][j]+1;  //达到相等时为 1种方法 
			else if(a[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];   //选了这道菜与没选这菜次数和 
		} 
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
