#include <bits/stdc++.h>
using namespace std;
int dp[100][100],w[100],v[100];      //用dp[i][j]二维数组储存子问题最优解，直到算到最后一个得当前最优解 
int main()
{
	int n,bag;
	cout<<"物品描述："<<endl;
	cin>>n; 
	for(int i=1;i<=n;i++)    //预留0值，便于最先时直接放入背包 
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cout<<"背包大小:"<<endl;
	cin>>bag;
	for(int i=1;i<=n;i++)               //考虑前i个物品最优解 
	{
		for(int j=0;j<=bag;j++)      //考虑前j个容积最优解 (之所以计算每种容积下是否装入i，是为了给后面可能各种情况的调用) 
		{
			if(j<w[i]) dp[i][j]=dp[i-1][j];   //容积不够，则不能装 
			else
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]); //判断背包容积为j时装还是不装,j-w[i]调用了装后容积的最优解(状态转移方程) 
		}
	}
	cout<<dp[n][bag]<<endl;
	return 0;
} 
