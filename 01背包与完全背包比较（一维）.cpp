#include <bits/stdc++.h>	//该代码为洛谷P1616 AC代码 （完全背包问题）
using namespace std;
int t,m,a[10001],b[10001],dp[10000001];
int main()
{
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=a[i];j<=t;j++){	//当题目变为01背包时(只能取一次)，该循环应变为for(int j=t;j>=a[i];j--),其余不变
			if(a[i]>j) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
	printf("%d",dp[t]);
	return 0;
}

//区别解释:
//当for为j--的形式时，可保证每个物品只被取一次（先算的后面的dp不能被前面的dp利用）
//当for为j++的形式时，每个物品变成可取多次（先算的前面的dp可被后面的利用）
