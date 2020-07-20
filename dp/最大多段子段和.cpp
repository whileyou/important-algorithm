//https://vjudge.net/contest/381844#problem/A
//A
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
int m,n,a[1000001],dp[1000001],MAX[1000001],ans;
int main()
{
	while(~scanf("%d %d",&m,&n)){
		memset(dp,0,sizeof(dp));
		memset(MAX,0,sizeof(MAX));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			ans=-99999999;
			for(int j=i;j<=n;j++){
				dp[j]=max(dp[j-1]+a[j],MAX[j-1]+a[j]);
				MAX[j-1]=ans;
				ans=max(ans,dp[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
