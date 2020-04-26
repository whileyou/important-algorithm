#include <bits/stdc++.h>
using namespace std;
int t,m,a[10001],b[10001],dp[10000001];
int main()
{
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=a[i];j<=t;j++){
			if(a[i]>j) dp[j]=dp[j];
			else dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		}
	}
	printf("%d",dp[t]);
	return 0;
}
